#include <string>

#ifndef UTILS_H
#define UTILS_H

const char *extractName(const char *filename);
std::string formatLine(const std::string &line, int indentation);
std::string escapeSpecialCharacters(const std::string &line);
bool generateSnippetBody(std::ifstream &file, const char *extractedName);

#endif
