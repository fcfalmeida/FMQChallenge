#include "sprite_node.h"

SpriteNode::SpriteNode(const sf::Texture& texture)
: sprite(texture)
{
    sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
