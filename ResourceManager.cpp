#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::AddTexture(std::string name, sf::Texture* resource)
{
	TexturePool.AddResource(name, resource);
}

void ResourceManager::AddSoundFX(std::string name, sf::SoundBuffer* resource)
{
	SoundFXPool.AddResource(name, resource);
}

sf::Texture* ResourceManager::GetTexture(std::string name)
{
	return TexturePool.GetResource(name);
}

sf::SoundBuffer* ResourceManager::GetSoundFX(std::string name)
{
	return SoundFXPool.GetResource(name);
}