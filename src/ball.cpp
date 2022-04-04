#include "ball.h"
#include <iostream>

Ball::Ball(sf::Texture& texture, sf::Vector2f velocity)
    :   SpriteElement(texture),
        velocity(velocity)
{
}

void Ball::update(sf::Time deltaTime)
{
    if (!canMove) return;
    
    // Set random ball color every COLOR_CHANGE_INTERVAL seconds
    if (colorClock.getElapsedTime().asSeconds() > COLOR_CHANGE_INTERVAL)
    {
        colorClock.restart();

        int randIdx = rand() % BALL_COLORS.size();
        element.setColor(BALL_COLORS[randIdx]);
    }

    move(velocity * deltaTime.asSeconds());
}

sf::Color Ball::getColor() const
{
    return element.getColor();
}
