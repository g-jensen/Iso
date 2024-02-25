#include "../headers/Vec.hpp"

float vec::dist(Vec2f v1, Vec2f v2) {
  return sqrt((v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y));
}

float vec::dist(Vec3f v1, Vec3f v2) {
  return sqrt((v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z));
}

Vec2f vec::normal(Vec2f v) {
  if (v == Vec2f()) {return Vec2f(1,0);}
  return v / sqrt(v.x*v.x + v.y*v.y);
}

Vec3f vec::normal(Vec3f v) {
  if (v == Vec3f()) {return vec::i;}
  return v / sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

float vec::dot(Vec2f v1, Vec2f v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

float vec::dot(Vec3f v1, Vec3f v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec2f vec::cross(Vec2f v1) {
  return Vec2f(-v1.y,v1.x);
}

Vec3f vec::cross(Vec3f v1, Vec3f v2) {
  return Vec3f(v1.y*v2.z - v1.z*v2.y,v1.z*v2.x - v1.x*v2.z,v1.x*v2.y - v1.y*v2.x);
}