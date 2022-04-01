#pragma once

#include <SFML/Graphics.hpp>
#include "scene.h"

class Game
{
public:
    Game();
    void start();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    const int targetFrameRate;
    const sf::Time timePerFrame;
    Scene scene;
};
