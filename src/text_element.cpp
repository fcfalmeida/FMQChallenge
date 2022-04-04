#include "text_element.h"

TextElement::TextElement()
{
}

TextElement::TextElement(sf::Font& font, int fontSize, sf::Color textColor, std::string text)
{
    element.setFont(font);
    element.setCharacterSize(fontSize);
    element.setFillColor(textColor);
    setText(text);

    setPivot(Center);
}

void TextElement::setText(std::string text)
{
    element.setString(text);
}