/*
				ResourceManager.hpp

	Description:
		ResourceManager gives us an interface to 
		access the resouces from the ResourcePools.
*/
#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#pragma once

#include <string>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePool.hpp"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void AddTexture(std::string name, sf::Texture* resource);
	void AddSoundFX(std::string name, sf::SoundBuffer* resource);

	sf::Texture* GetTexture(std::string name);
	sf::SoundBuffer* GetSoundFX(std::string name);

private:
	ResourcePool<sf::Texture> TexturePool;
	ResourcePool<sf::SoundBuffer> SoundFXPool;
};

#endif