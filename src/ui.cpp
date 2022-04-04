#include "ui.h"

UI::UI(sf::RenderWindow& window, int windowWidth, int windowHeight)
:   windowWidth(windowWidth),
    windowHeight(windowHeight)
{
    loadAssets();
    createTopPanel();
    createBottomPanel();
}

void UI::loadAssets()
{
    topPanelTexture.loadFromFile("assets/sprites/top_panel.png");
    bottomPanelTexture.loadFromFile("assets/sprites/bottom_panel.png");
    font.loadFromFile("assets/fonts/screaming_neon.ttf");
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(topPanel);
    target.draw(bottomPanel);
    target.draw(creditsInText);
    target.draw(creditsOutText);
    target.draw(totalPlaysText);
}

void UI::createTopPanel()
{
    topPanel = SpriteElement(topPanelTexture);
    topPanel.setPivot(SpriteElement::TopLeft);

    creditsInText = TextElement(font, 50, sf::Color::Red, CREDITS_IN_TEXT + "0");
    creditsOutText = TextElement(font, 50, sf::Color::Red, CREDITS_OUT_TEXT + "0");
    totalPlaysText = TextElement(font, 50, sf::Color::Red, TOTAL_PLAYS_TEXT + "0");

    creditsInText.setPivot(TextElement::BottomLeft);
    creditsOutText.setPivot(TextElement::BottomCenter);
    totalPlaysText.setPivot(TextElement::BottomRight);

    float panelWidth = topPanel.getDimensions().x;
    float panelHeight = topPanel.getDimensions().y;

    creditsInText.setPosition(sf::Vector2f(panelWidth / 14, panelHeight / 2));
    creditsOutText.setPosition(sf::Vector2f(panelWidth / 2, panelHeight / 2));
    totalPlaysText.setPosition(sf::Vector2f(panelWidth / 1.1, panelHeight / 2));
}

void UI::createBottomPanel()
{
    bottomPanel = SpriteElement(bottomPanelTexture);
    bottomPanel.setPivot(SpriteElement::BottomLeft);
    bottomPanel.setPosition(sf::Vector2f(0, windowHeight));
}

void UI::updateCreditsInserted(int newValue)
{
    creditsInText.setText(CREDITS_IN_TEXT + std::to_string(newValue));
}

void UI::updateCreditsExtracted(int newValue)
{
    creditsOutText.setText(CREDITS_OUT_TEXT + std::to_string(newValue));
}

void UI::updateTotalPlays(int newValue)
{
    totalPlaysText.setText(TOTAL_PLAYS_TEXT + std::to_string(newValue));
}