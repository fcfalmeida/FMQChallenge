#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "sprite_element.h"

class Ball : public SpriteElement
{
public:
    Ball(sf::Texture& texture, sf::Vector2f velocity);
    void update(sf::Time deltaTime);
    sf::Color getColor() const;
    
    bool canMove = false;
private:
    sf::Vector2f velocity;
    sf::Clock colorClock;
    
    const float COLOR_CHANGE_INTERVAL = 0.5f;
    const std::vector<sf::Color> BALL_COLORS = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow
    };
};
