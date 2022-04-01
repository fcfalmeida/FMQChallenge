#pragma once

#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

enum AssetID
{
    Background,
    Ball
};

template <typename Asset, typename Identifier>
class AssetManager
{
public:
    void load(Identifier id, const std::string& filename);
    Asset& get(Identifier id) const;
private:
    void addAsset(Identifier id, std::unique_ptr<Asset> asset);

    std::map<Identifier, std::unique_ptr<Asset>> assetMap;
};

typedef AssetManager<sf::Texture, AssetID> TextureManager;

template <typename Asset, typename Identifier>
void AssetManager<Asset, Identifier>::load(Identifier id, const std::string& filename)
{
    std::unique_ptr<Asset> asset(new Asset());
    asset->loadFromFile(filename);

    addAsset(id, std::move(asset));
}

template <typename Asset, typename Identifier>
Asset& AssetManager<Asset, Identifier>::get(Identifier id) const
{
	auto found = assetMap.find(id);

	return *found->second;
}

template <typename Asset, typename Identifier>
void AssetManager<Asset, Identifier>::addAsset(Identifier id, std::unique_ptr<Asset> asset) 
{
	assetMap.insert(std::make_pair(id, std::move(asset)));
}