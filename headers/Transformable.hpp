#pragma once

#include "Vec.hpp"

class Transformable {
public:
  virtual void move(Vec3f delta);
  virtual Vec3f getPosition();
  virtual void setPosition(Vec3f position);
  virtual Vec3f getSize();
  virtual void setSize(Vec3f size);
protected:
  Vec3f position;
  Vec3f size;
};