/*

Class name: ResourceManager

Description: Holds commonly used resources, like textures and sounds. 
			 Each pool can be accessed to make loading and reusing
			 resources easier and more efficient.

*/

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#pragma once

#include <map>
#include <string>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	// Mutators
	void AddTexture(std::string name, sf::Texture* texture);
	void AddSoundFX(std::string name, sf::SoundBuffer* buffer);

	// Accessors
	sf::Texture* GetTexture(std::string name);
	sf::SoundBuffer* GetSoundBuffer(std::string name);

private:
	std::vector<std::pair<std::string, sf::Texture*>> TexturePool;
	std::vector<std::pair<std::string, sf::SoundBuffer*>> SoundFXPool;
};

#endif