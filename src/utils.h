#include <string>

#ifndef UTILS_H
#define UTILS_H

const char *extractName(const char *filename);
std::string escapeSpecialCharacters(const std::string &line);
bool generateSnippetBody(std::ifstream &file, const char *extractedName);

#endif
