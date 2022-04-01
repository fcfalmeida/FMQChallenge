#pragma once

#include <array>
#include <SFML/Graphics.hpp>
#include "node.h"
#include "asset_manager.h"

class Scene
{
public:
    Scene(sf::RenderWindow& window);
    void draw();
    void update(sf::Time deltaTime);

private:
    void loadScene();
    void loadTextures();

    enum Layer
    {
        Background,
        Foreground,
        NumLayers
    };

    sf::RenderWindow& window;
    Node nodeTree;
    std::array<Node*, NumLayers> layers;
    AssetManager<sf::Texture, AssetID> textures;
};