#pragma once

#include <SFML/Graphics.hpp>
#include "element.h"

class SpriteElement : public Element<sf::Sprite>
{
public:
    SpriteElement();
    SpriteElement(sf::Texture& texture);
};