#pragma once

#include <SFML/Graphics.hpp>

class Node : public sf::Transformable, public sf::Drawable
{
public:
    typedef std::unique_ptr<Node> NodePtr;

    void addChild(NodePtr child);
    void update(sf::Time deltaTime);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time deltaTime);
    void updateChildren(sf::Time deltaTime);

    std::vector<NodePtr> children;
    Node* parent;
};