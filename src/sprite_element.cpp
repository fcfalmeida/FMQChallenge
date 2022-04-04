#include "sprite_element.h"

SpriteElement::SpriteElement(sf::Texture& texture)
{
    element = sf::Sprite(texture);
    setPivot(Center);
}

SpriteElement::SpriteElement()
{

}
