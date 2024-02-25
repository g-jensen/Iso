#pragma once

#include <math.h>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

typedef sf::Vector2f Vec2f;
typedef sf::Vector3f Vec3f;
typedef sf::Vector2<unsigned int> Vec2ui;
typedef sf::Vector3<unsigned int> Vec3ui;

namespace vec {
  inline const Vec3f i = Vec3f(1,0,0);
  inline const Vec3f j = Vec3f(0,1,0);
  inline const Vec3f k = Vec3f(0,0,1);
  float dist(Vec2f v1, Vec2f v2);
  float dist(Vec3f v1, Vec3f v2);
  Vec2f normal(Vec2f v);
  Vec3f normal(Vec3f v);
  float dot(Vec2f v1, Vec2f v2);
  float dot(Vec3f v1, Vec3f v2);
  Vec2f cross(Vec2f v1);
  Vec3f cross(Vec3f v1, Vec3f v2);
};