#pragma once

#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Vec.hpp"
#include "math.hpp"

typedef sf::RenderWindow Window;

namespace window {
  inline Window* window = nullptr;
  void registerEvents(sf::Event event);
  Vec2f world_to_screen(Vec3f pos);
  inline std::function<void(void)> onPressW = [](){};
  inline std::function<void(void)> onPressA = [](){};
  inline std::function<void(void)> onPressS = [](){};
  inline std::function<void(void)> onPressD = [](){};
};