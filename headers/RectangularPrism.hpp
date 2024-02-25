#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Drawable.hpp"
#include "Vec.hpp"
#include "Transformable.hpp"

class RectangularPrism: public Drawable, public Transformable {
public:
  RectangularPrism(Vec3f position, Vec3f size);
  void draw(Window* window);
  void setTexture(sf::Texture &texture);
  void setPosition(Vec3f position);
private:
  void updateVertices();
  sf::Texture* texture_array[3];
  sf::VertexArray quads[3];
};