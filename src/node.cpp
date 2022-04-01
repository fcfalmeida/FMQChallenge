#include "node.h"

void Node::addChild(NodePtr child)
{
    child->parent = this;
    children.push_back(std::move(child));
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(target, states);
    drawChildren(target, states);
}

void Node::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void Node::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const NodePtr& child : children)
        child->draw(target, states);
}

void Node::update(sf::Time deltaTime)
{
    updateCurrent(deltaTime);
    updateChildren(deltaTime);
}

void Node::updateCurrent(sf::Time deltaTime)
{

}

void Node::updateChildren(sf::Time deltaTime)
{
    for (const NodePtr& child : children)
        child->update(deltaTime);
}