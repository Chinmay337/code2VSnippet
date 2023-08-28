#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include "utils.h"

const int MAX_CONCURRENT_THREADS = 8;

std::vector<std::string> bodyLines;
std::mutex mutex;
void processLine(std::ifstream &file, size_t index)
{
  std::string line;
  {
    std::lock_guard<std::mutex> lock(mutex);
    if (!std::getline(file, line))
    {
      bodyLines[index] = "";
      return; // No more lines to process
    }
  }

  // Convert leading spaces to tabs
  size_t spaces = 0;
  for (char c : line)
  {
    if (c == ' ')
      spaces++;
    else
      break;
  }
  std::string leadingTabs;
  leadingTabs.assign(spaces / 4, '\t'); // Assuming 4 spaces per tab

  // Now escape the rest of the line
  std::string noLeadingSpacesLine = line.substr(spaces);
  std::string escapedLine = escapeSpecialCharacters(leadingTabs + noLeadingSpacesLine);

  if (!escapedLine.empty())
  {
    std::string formattedLine = "      \"" + escapedLine + "\"";
    std::lock_guard<std::mutex> lock(mutex); // Protect writing to the shared vector
    bodyLines[index] = formattedLine;
  }
  else
  {
    std::lock_guard<std::mutex> lock(mutex); // Protect writing to the shared vector
    bodyLines[index] = "      \"\"";
  }
}

bool generateSnippetBody(std::ifstream &file, const char *extractedName)
{
  size_t totalLines = std::count(
                          std::istreambuf_iterator<char>(file),
                          std::istreambuf_iterator<char>(),
                          '\n') +
                      1;

  bodyLines.resize(totalLines);

  file.clear();
  file.seekg(0);

  std::vector<std::thread> threads;
  for (size_t i = 0; i < totalLines; ++i)
  {
    threads.emplace_back(processLine, std::ref(file), i);
  }

  for (auto &thread : threads)
  {
    thread.join();
  }

  std::cout << "\""
            << "Snippet Title Here"
            << "\": {" << std::endl;
  std::cout << "    \"prefix\":\"" << extractedName << "\"," << std::endl;
  std::cout << "    \"body\": [";

  for (size_t i = 0; i < bodyLines.size(); ++i)
  {
    if (bodyLines[i] == "      \"\"")
      continue;
    if (i > 0)
    {
      std::cout << ",";
    }
    std::cout << "\n"
              << bodyLines[i];
  }

  std::cout << "\n    ]," << std::endl;
  std::cout << "    \"description\": \"Benchmark tests using mock data for standard and Sonic JSON decoding.\"" << std::endl;
  std::cout << "}," << std::endl;

  return true;
}
