#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "ball.h"

class BallHolder : public sf::Drawable
{
public:
    BallHolder(int windowHeight);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void createBalls();
    void launchBalls();
    void update(sf::Time deltaTime);
    void resetBalls();

    const int ballCount = 50;
    int ballsDone = 0;
    std::vector<Ball> balls;
private:
    void loadAssets();

    const int windowHeight;

    sf::Texture ballTexture;
    static constexpr float BALL_LAUNCH_INTERVAL = 0.05f;
    static const int BALL_STOP_Y = 130;
    int nextBallIndex = 0;
    sf::Clock ballClock;
};
