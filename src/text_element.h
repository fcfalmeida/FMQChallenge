#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "element.h"

class TextElement : public Element<sf::Text>
{
public:
    TextElement();
    TextElement(sf::Font& font, int fontSize, sf::Color textColor, std::string text);
    void setText(std::string text);
};