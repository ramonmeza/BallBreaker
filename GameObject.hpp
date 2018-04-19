/*
				GameObject.hpp

	Description:
		GameObject is a abstract base class for all
		objects in the game world. Derived classes
		must implement the Load() function.
*/
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

class GameObject : public sf::Drawable
{
public:
	GameObject() {}
	virtual ~GameObject() {}
	
	virtual void Load() = 0;
	virtual void Update() {}

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {}
};

#endif