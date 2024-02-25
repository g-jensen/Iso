#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <fstream>

namespace utils {
  bool str_startsWith(std::string string, std::string input);
  std::vector<std::string> str_split(std::string string, char delimiter);
  std::vector<std::string> get_lines(std::string filePath);
};