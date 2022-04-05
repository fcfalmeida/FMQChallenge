#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// Restrict template to types that implement getLocalBounds()
template <class T>
concept HasBounds = std::is_base_of<sf::Sprite, T>::value || std::is_base_of<sf::Text, T>::value;

template<HasBounds E>
class Element : public sf::Transformable, public sf::Drawable
{
public:
    virtual void update(sf::Time deltaTime);
    sf::Vector2f getDimensions() const;

    enum Pivot
    {
        TopLeft,
        TopCenter,
        TopRight,
        CenterLeft,
        Center,
        CenterRight,
        BottomLeft,
        BottomCenter,
        BottomRight
    };
    
    void setPivot(Pivot pivot);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
    E element;
    Pivot pivot;
};

template<HasBounds E>
void Element<E>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(element, states);
}

template<HasBounds E>
void Element<E>::update(sf::Time deltaTime)
{
}

template<HasBounds E>
sf::Vector2f Element<E>::getDimensions() const
{
    sf::FloatRect bounds = element.getLocalBounds();

    auto dims = sf::Vector2f(bounds.width * getScale().x, bounds.height * getScale().y);
    return dims;
}

template<HasBounds E>
void Element<E>::setPivot(Pivot pivot)
{
    sf::FloatRect bounds = element.getLocalBounds();

    float width = bounds.width;
    float height = bounds.height;

    float x = 0;
    float y = 0;

    switch (pivot)
    {
        case TopLeft:
            x = 0;
            y = 0;
            break;
        case TopCenter:
            x = width / 2;
            y = 0;
            break;
        case TopRight:
            x = width;
            y = 0;
            break;
        case CenterLeft:
            x = 0;
            y = height / 2;
            break;
        case Center:
            x = width / 2;
            y = height / 2;
            break;
        case CenterRight:
            x = width;
            y = height / 2;
            break;
        case BottomLeft:
            x = 0;
            y = height;
            break;
        case BottomCenter:
            x = width / 2;
            y = height;
            break;
        case BottomRight:
            x = width;
            y = height;
            break;
    }

	element.setOrigin(sf::Vector2f(x, y));
}