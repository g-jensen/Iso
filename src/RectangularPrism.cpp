#include "../headers/RectangularPrism.hpp"

RectangularPrism::RectangularPrism(Vec3f position, Vec3f size) {
  this->position = position;
  this->size = size;

  quads[0] = sf::VertexArray(sf::Quads,4);
  quads[1] = sf::VertexArray(sf::Quads,4);
  quads[2] = sf::VertexArray(sf::Quads,4);

  texture_array[0] = nullptr;
  texture_array[1] = nullptr;
  texture_array[2] = nullptr;

  updateVertices();
}

void RectangularPrism::updateVertices() {
  quads[0][0] = {window::world_to_screen({position.x+size.x,position.y,position.z}),sf::Color::White,{0,0}};
  quads[0][1] = {window::world_to_screen({position.x+size.x,position.y,position.z+size.z}),sf::Color::White,{0,16}};
  quads[0][2] = {window::world_to_screen({position.x+size.x,position.y+size.y,position.z+size.z}),sf::Color::White,{16,16}};
  quads[0][3] = {window::world_to_screen({position.x+size.x,position.y+size.y,position.z}),sf::Color::White,{16,0}};

  quads[1][0] = {window::world_to_screen({position.x+size.x,position.y+size.y,position.z}),sf::Color::White,{0,0}};
  quads[1][1] = {window::world_to_screen({position.x+size.x,position.y+size.y,position.z+size.z}),sf::Color::White,{0,16}};
  quads[1][2] = {window::world_to_screen({position.x,position.y+size.y,position.z+size.z}),sf::Color::White,{16,16}};
  quads[1][3] = {window::world_to_screen({position.x,position.y+size.y,position.z}),sf::Color::White,{16,0}};

  quads[2][0] = {window::world_to_screen({position.x+size.x,position.y+size.y,position.z+size.z}),sf::Color::White,{0,0}};
  quads[2][1] = {window::world_to_screen({position.x+size.x,position.y,position.z+size.z}),sf::Color::White,{0,16}};
  quads[2][2] = {window::world_to_screen({position.x,position.y,position.z+size.z}),sf::Color::White,{16,16}};
  quads[2][3] = {window::world_to_screen({position.x,position.y+size.y,position.z+size.z}),sf::Color::White,{16,0}};
}

void RectangularPrism::setPosition(Vec3f position) {
  this->position = position;
  updateVertices();
}

void RectangularPrism::draw(Window* window) {
  for (int i = 0; i < 3; i++) {
    if (texture_array[i] != nullptr)
      window->draw(quads[i],texture_array[i]);
    else
      window->draw(quads[i]);
  }
}

void RectangularPrism::setTexture(sf::Texture &texture) {
  texture_array[0] = &texture;
  texture_array[1] = &texture;
  texture_array[2] = &texture;
}