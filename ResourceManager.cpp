#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::AddTexture(std::string name, sf::Texture* texture)
{
	TexturePool.emplace_back(name, texture);
}

void ResourceManager::AddSoundFX(std::string name, sf::SoundBuffer* buffer)
{
	SoundFXPool.emplace_back(name, buffer);
}

sf::Texture* ResourceManager::GetTexture(std::string name)
{
	for (auto itr = TexturePool.begin(); itr != TexturePool.end(); itr++)
	{
		if (itr->first == name)
		{
			return itr->second;
		}
	}

	return nullptr;
}

sf::SoundBuffer* ResourceManager::GetSoundBuffer(std::string name)
{
	for (auto itr = SoundFXPool.begin(); itr != SoundFXPool.end(); itr++)
	{
		if (itr->first == name)
		{
			return itr->second;
		}
	}

	return nullptr;
}