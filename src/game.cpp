#include "game.h"
#include <iostream>

Game::Game()
:   window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "FMQ Challenge"),
    timePerFrame(sf::seconds(1.f / TARGET_FRAMERATE)),
    ui(window, WINDOW_WIDTH, WINDOW_HEIGHT),
    ballHolder(WINDOW_HEIGHT)
{
    window.setKeyRepeatEnabled(false);

    loadAssets();

    background = SpriteElement(backgroundTexture);
    background.setPivot(SpriteElement::TopLeft);

    ballHolder.createBalls();
}

void Game::loadAssets()
{
    backgroundTexture.loadFromFile("assets/sprites/background.png");
}

void Game::start()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
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
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                switch (state)
                {
                    case GameState::Uninitialized:
                        if (checkCredits())
                            play();
                        break;
                    case GameState::Playing:
                    case GameState::Paused:
                        togglePause();
                        break;
                    case GameState::GameOver:
                        reset();
                        break;
                }
            }
            if (event.key.code == sf::Keyboard::Z)
                insertCredits(1);
            if (event.key.code == sf::Keyboard::X)
                extractCredits();
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    switch (state)
    {
        case GameState::Playing:
            ballHolder.launchBalls();
            ballHolder.update(deltaTime);

            if (ballHolder.ballsDone >= ballHolder.ballCount)
                gameOver();

            break;
        default:
            break;
    }
}

void Game::render()
{
    window.clear();

    window.draw(background);
    window.draw(ui);
    window.draw(ballHolder);

    window.display();
}

bool Game::checkCredits()
{
    return insertedCredits >= PLAY_COST;
}

void Game::insertCredits(int amount)
{
    insertedCredits += amount;
    ui.updateCreditsInserted(insertedCredits);
}

void Game::extractCredits()
{
    extractedCredits += insertedCredits;
    insertedCredits = 0;

    ui.updateCreditsInserted(insertedCredits);
    ui.updateCreditsExtracted(extractedCredits);
}

void Game::calculateWinnings()
{
    int creditsWon = 0;

    for (auto& ball : ballHolder.balls)
    {
        if (ball.getColor() == WINNING_COLOR)
            creditsWon++;
    }

    insertCredits(creditsWon);

    std::cout << "Credits: " << insertedCredits << std::endl;
}

void Game::play()
{
    if (!checkCredits()) return;

    state = GameState::Playing;
    insertCredits(-PLAY_COST);
}

void Game::gameOver()
{
    calculateWinnings();
    state = GameState::GameOver;

    totalPlays++;
    ui.updateTotalPlays(totalPlays);
}

void Game::reset()
{
    ballHolder.resetBalls();
    play();
}

void Game::togglePause()
{
    if (state == GameState::Paused)
        state = GameState::Playing;
    else
        state = GameState::Paused;
}