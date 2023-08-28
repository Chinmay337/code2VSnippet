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
  const char *extractedName = extractName(filename);

  std::ifstream file(filename);

  if (!file)
  {
    std::cerr << "Error opening file: " << filename << std::endl;
    return 2;
  }

  if (!generateSnippetBody(file, extractedName))
  {
    std::cerr << "Error generating snippet body" << std::endl;
    return 3;
  }

  file.close();

  return 0;
}

/*

# Including Libs
g++ -std=c++20 -o main main.cpp utils/util.cpp

g++ -std=c++20 -o main main.cpp utils.cpp transform.cpp -lpthread

# Development
g++ -std=c++20 -o main main.cpp

&& ./main

# Production
g++ -std=c++20 -O3 -o quicksort quicksort.cpp && ./quicksort



"Command Description": {
    "prefix": "<filename>",
    "body": [
      "func createWebServer() {",

      "\thttp.HandleFunc(\"/\", func(w http.ResponseWriter, r *http.Request) {",
      "\t\tfmt.Fprintf(w, \"Hello World\")",
      "\t})",
      "",
      "\thttp.ListenAndServe(\":8080\", nil)",
      "\t//curl localhost:8080",

      "}"
    ],
    "description": "Log output to console"
  },


*/