#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

const char *extractName(const char *filename)
{
  const char *dot = std::strchr(filename, '.');
  if (dot == nullptr)
  {
    return filename; // No dot found, return the original string
  }

  int length = dot - filename;
  char *extracted = new char[length + 1];
  std::strncpy(extracted, filename, length);
  extracted[length] = '\0';

  std::cout << "Creating Snippet for " << extracted << '\n'
            << std::endl;

  return extracted;
}

std::string escapeSpecialCharacters(const std::string &line)
{
  std::string escapedLine;
  for (char c : line)
  {
    switch (c)
    {
    case '\\':
      escapedLine += "\\\\";
      break;
    case '"':
      escapedLine += "\\\"";
      break;
    case '\t':
      escapedLine += "\\t"; // This is the change. We want the output to be \\t
      break;
    default:
      escapedLine += c;
      break;
    }
  }
  return escapedLine;
}
