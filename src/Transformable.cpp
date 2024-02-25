#include "../headers/Transformable.hpp"

void Transformable::move(Vec3f delta) {
  setPosition(getPosition()+delta);
}

Vec3f Transformable::getPosition() {
  return position;
}

void Transformable::setPosition(Vec3f position) {
  this->position = position;
}

Vec3f Transformable::getSize() {
  return size;
}

void Transformable::setSize(Vec3f size) {
  this->size = size;
}