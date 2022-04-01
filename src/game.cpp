#include "game.h"

Game::Game()
:   window(sf::VideoMode(800, 600), "FMQ Challenge"),
    targetFrameRate(60),
    timePerFrame(sf::seconds(1.f / targetFrameRate)),
    scene(window)
{
}

void Game::start()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            processEvents();
            update(timePerFrame);
        }
        
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time deltaTime)
{

}


void Game::render()
{
    window.clear();
    scene.draw();
    window.display();
}