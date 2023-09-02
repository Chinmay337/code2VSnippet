#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "utils.h"

#include <algorithm>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  const char *filename = argv[1];
  const char *extractedName = extractName(filename); // get file name

  std::ifstream file(filename); // read file content

  if (!file)
  {
    std::cerr << "Error opening file: " << filename << std::endl;
    return 2;
  }

  if (!generateSnippetBody(file, extractedName)) // try to parse each line number and see if all is successful
  {
    std::cerr << "Error generating snippet body" << std::endl;
    return 3;
  }

  file.close();

  return 0;
}

/*

g++ -std=c++20 -o main main.cpp utils.cpp transform.cpp -lpthread

*/