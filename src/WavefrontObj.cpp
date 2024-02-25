#include "../headers/WavefrontObj.hpp"

Vec3f parseVertices(const std::string& line) {
  std::vector<std::string> tokens = utils::str_split(line,' ');
  return Vec3f(stof(tokens[1]),stof(tokens[2]),stof(tokens[3]));
}

std::vector<unsigned int> parseFaces(const std::string& line) {
  std::vector<std::string> tokens = utils::str_split(line,' ');
  std::vector<unsigned int> output;
  for (size_t i = 1; i < tokens.size(); i++) {
    // vertex_index/texture_index/normal_index 
    std::vector<std::string> v_t_n = utils::str_split(tokens[i],'/');
    output.push_back(stoi(v_t_n[0]));
  }
  return output;
}

WavefrontObj parseObj(const std::string& path) {
  std::vector<std::string> lines = utils::get_lines(path);
  WavefrontObj output;
  for (const std::string& line : lines) {
    if (utils::str_startsWith(line,"v ")) {
      output.vertices.push_back(parseVertices(line));
    } else if (utils::str_startsWith(line,"f ")) {
      output.faces.push_back(parseFaces(line));
    }
  }
  return output;
}