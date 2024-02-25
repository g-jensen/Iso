#include "headers/Window.hpp"
#include "headers/RectangularPrism.hpp"
#include "headers/WavefrontObj.hpp"

#include <SFML/Window/Event.hpp>

#include <iostream>

Vec3f transform(Vec3f v) {
  return Vec3f(v.x,v.z,v.y);
}

int main() {
  window::window = new Window({800, 600, 32},"IsometricEngine");
  
  sf::Texture texture;
  texture.loadFromFile("resources/face.png");
  sf::Vector2u size = texture.getSize();
  // RectangularPrism r(Vec3f(),{100,100,100});
  // r.setTexture(texture);

  // window::onPressW = [&r](){r.move(Vec3f(-1,0,0));};
  // window::onPressA = [&r](){r.move(Vec3f(0,-1,0));};
  // window::onPressS = [&r](){r.move(Vec3f(1,0,0));};
  // window::onPressD = [&r](){r.move(Vec3f(0,1,0));};

  std::string path = "specc/parseObj/numbered_cube.obj";//"resources/lamp.obj";
  WavefrontObj cubeObj = parseObj(path);
  sf::VertexArray faces[cubeObj.faces.size()];
  for (size_t i = 0; i < cubeObj.faces.size(); i++) {
    std::vector<unsigned int> face = cubeObj.faces[i];
    faces[i] = sf::VertexArray(sf::Quads,face.size());
    faces[i][0] = {window::world_to_screen(transform(50.f*cubeObj.vertices[face[0]-1])),sf::Color::White,{0,0}};
    faces[i][1] = {window::world_to_screen(transform(50.f*cubeObj.vertices[face[1]-1])),sf::Color::White,{0,(float)size.y}};
    faces[i][2] = {window::world_to_screen(transform(50.f*cubeObj.vertices[face[2]-1])),sf::Color::White,{(float)size.x,(float)size.y}};
    faces[i][3] = {window::world_to_screen(transform(50.f*cubeObj.vertices[face[3]-1])),sf::Color::White,{(float)size.x,0}};
  }

  sf::Event event;
  while (window::window->isOpen()) {
    window::window->setFramerateLimit(60);

    window::registerEvents(event);

    window::window->clear(sf::Color::Black);
    for (size_t i = 0; i < cubeObj.faces.size(); i++) {
      window::window->draw(faces[i],&texture);
    }
    // window::window->draw(faces[0],&texture);
    // window::window->draw(faces[1],&texture);
    // window::window->draw(faces[2],&texture);
    // window::window->draw(faces[3],&texture);
    // window::window->draw(faces[4],&texture);
    // window::window->draw(faces[5],&texture);
    window::window->display();
  }
  delete window::window;
  return 0;
}