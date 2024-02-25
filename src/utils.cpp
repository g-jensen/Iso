#include "../headers/utils.hpp"

bool utils::str_startsWith(std::string string, std::string input) {
  return string.substr(0,input.size()) == input;
}

std::vector<std::string> utils::str_split(std::string string, char delimiter) {
  std::vector<std::string> out;
  if (string.empty()) {return out;}
  std::stringstream ss(string);
  std::string str;
  while(getline(ss,str,delimiter)) {
    out.push_back(str);
  }
  return out;
}

std::vector<std::string> utils::get_lines(std::string filePath) {
  std::ifstream file;
  file.open(filePath);
  std::stringstream ss;
  file >> ss.rdbuf();
  file.close();
  return utils::str_split(ss.str(),'\n');
}