#include "ball_holder.h"

BallHolder::BallHolder(int windowHeight)
:   windowHeight(windowHeight)
{
    loadAssets();
    createBalls();
}

void BallHolder::loadAssets()
{
    ballTexture.loadFromFile("assets/sprites/ball.png");
}

void BallHolder::createBalls()
{
    balls.clear();

    for (int i = 0; i < ballCount; i++)
    {
        Ball ball(ballTexture, sf::Vector2f(0.f, -500.f));

        auto dims = ball.getDimensions();

        ball.setPosition(sf::Vector2f((i+1) * ((ball.getDimensions().x / 2) + 15), windowHeight - 130));

        balls.push_back(ball);
    }
}

void BallHolder::launchBalls()
{
    // Launch one ball at a time with a delay
    if (ballClock.getElapsedTime().asSeconds() > BALL_LAUNCH_INTERVAL
        && nextBallIndex < balls.size())
    {
        ballClock.restart();

        balls[nextBallIndex].canMove = true;

        nextBallIndex++;
    }
}

void BallHolder::update(sf::Time deltaTime)
{
    // Update balls unless they have reached the y limit
    for (auto& ball : balls)
    {
        if (ball.getPosition().y <= BALL_STOP_Y)
        {
            // Only count ball as done if it wasn't already stopped
            if (ball.canMove)
            {
                ball.canMove = false;
                ballsDone++;
            }
        }
        else
            ball.update(deltaTime);
    }
}

void BallHolder::resetBalls()
{
    nextBallIndex = 0;
    ballsDone = 0;

    createBalls();
}

void BallHolder::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& ball : balls)
        target.draw(ball);
}