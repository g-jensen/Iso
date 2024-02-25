#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "Window.hpp"

class Drawable {
public:
  virtual void draw(Window* window) = 0;
  virtual void setTexture(sf::Texture &texture) = 0;
};