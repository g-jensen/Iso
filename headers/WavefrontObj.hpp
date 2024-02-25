#pragma once

#include <vector>
#include <string>

#include "Vec.hpp"
#include "utils.hpp"

typedef struct WavefrontObj {
  std::vector<Vec3f> vertices; // positions of the vertices
  std::vector<std::vector<unsigned int>> faces; // each std::vector<unsigned int> represents the indices of vertices to make an n-gon
} WavefrontObj;

static Vec3f parseVertices(const std::string& line);
static std::vector<unsigned int> parseFaces(const std::string& line);
WavefrontObj parseObj(const std::string& path);
