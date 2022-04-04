#pragma once

#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <SFML/Graphics.hpp>
#include "sprite_element.h"
#include "ball_holder.h"
#include "ui.h"

class Game
{
public:
    Game();
    void start();
private:
    // Setup and main game loop
    void loadAssets();
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    // Background
    sf::Texture backgroundTexture;
    SpriteElement background;

    // Balls
    BallHolder ballHolder;

    // Credits
    bool checkCredits();
    void insertCredits(int amount);
    void extractCredits();
    void calculateWinnings();

    // Game states
    void play();
    void gameOver();
    void reset();
    void togglePause();

    // Window and UI
    static const int WINDOW_WIDTH = 1280;
    static const int WINDOW_HEIGHT = 900;
    static const int TARGET_FRAMERATE = 60;
    sf::RenderWindow window;
    const sf::Time timePerFrame;
    UI ui;

    // Credits and plays
    static const int PLAY_COST = 1;
    int insertedCredits = 0;
    int extractedCredits = 0;
    const sf::Color WINNING_COLOR = sf::Color::Green;
    int totalPlays = 0;

    // Game states
    enum GameState
    {
        Uninitialized,
        Playing,
        Paused,
        GameOver
    };
    GameState state = GameState::Uninitialized;
};
