#include "../headers/Window.hpp"

Vec2f window::world_to_screen(Vec3f pos) {
  Vec2f v;
  v.x = (window->getSize().x >> 1) + (pos.x*cos_7PI_6) + (pos.y*cos_PI_6);
  v.y = (window->getSize().y >> 1) + (pos.x*-sin_7PI_6) + (pos.y*sin_PI_6) - pos.z;
  return v;
}

void window::registerEvents(sf::Event event) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    onPressW();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    onPressS();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    onPressA();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    onPressD();

  while (window->pollEvent(event))
    if (event.type == sf::Event::Closed)
      window->close();
}