#pragma once

#include "node.h"

class SpriteNode : public Node
{
public:
    SpriteNode(const sf::Texture& texture);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    sf::Sprite sprite;
};