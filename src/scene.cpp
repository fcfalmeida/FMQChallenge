#include "scene.h"
#include "sprite_node.h"

Scene::Scene(sf::RenderWindow& targetWindow)
:   window(targetWindow)
{
    loadTextures();
    loadScene();
}

void Scene::draw()
{
    window.draw(nodeTree);
}

void Scene::update(sf::Time deltaTime)
{
    nodeTree.update(deltaTime);
}

void Scene::loadTextures()
{
    textures.load(AssetID::Ball, "assets/ball.png");
}

void Scene::loadScene()
{
    for (std::size_t i = 0; i < NumLayers; ++i)
	{
		Node::NodePtr layer(new Node());
		layers[i] = layer.get();

		nodeTree.addChild(std::move(layer));
	}

    sf::Texture ballTexture = textures.get(AssetID::Ball);
    std::unique_ptr<SpriteNode> ball(new SpriteNode(ballTexture));

    // ball->setPosition(sf::Vector2(0.f, 0.f));

    // window.getView().getViewport().left;
    layers[Foreground]->addChild(std::move(ball));
}