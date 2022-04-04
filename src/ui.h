#pragma once

#include <SFML/Graphics.hpp>
#include "sprite_element.h"
#include "text_element.h"

class UI : public sf::Drawable
{
public:
    UI(sf::RenderWindow& window, int windowWidth, int windowHeight);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateCreditsInserted(int newValue);
    void updateCreditsExtracted(int newValue);
    void updateTotalPlays(int newValue);
private:
    void loadAssets();
    void createTopPanel();
    void createBottomPanel();

    const int windowWidth;
    const int windowHeight;

    static inline const std::string CREDITS_IN_TEXT = "IN: ";
    static inline const std::string CREDITS_OUT_TEXT = "OUT: ";
    static inline const std::string TOTAL_PLAYS_TEXT = "PLAYS: ";

    SpriteElement topPanel;
    SpriteElement bottomPanel;
    TextElement creditsInText;
    TextElement creditsOutText;
    TextElement totalPlaysText;

    sf::Texture topPanelTexture;
    sf::Texture bottomPanelTexture;
    sf::Font font;
};
