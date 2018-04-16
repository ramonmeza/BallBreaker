/*
				ResourcePool.hpp

	Description:
		ResourcePool is a generic class that holds 
		a given type of resource, such as textures 
		or sound effects.

		This class will take away the need to load
		multiple instances of the same resource to 
		help save space.
*/
#ifndef RESOURCEPOOL_HPP
#define RESOURCEPOOL_HPP
#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

template<class T>
class ResourcePool
{
public:
	ResourcePool() {}
	~ResourcePool()
	{
		pool.clear();
	}

	// Add a given resource to the pool with the given name
	void AddResource(std::string name, T* resource)
	{
		// Try to find if resource name already exists
		for (auto itr = pool.begin(); itr != pool.end(); itr++)
		{
			if (itr->first == name)
			{
				std::cout << "ResourcePool::AddResource(): The key \'" << name << "\' is already taken and the resource wasn't added." << std::endl;
				return;
			}
		}

		// If the resource name isn't taken then add it into the pool
		pool.emplace_back(name, resource);
	}

	// Return the resource linked to the name given
	T* GetResource(std::string name)
	{
		// Try to find the corresponding resource
		for (auto itr = pool.begin(); itr != pool.end(); itr++)
		{
			if (itr->first == name)
			{
				return itr->second;
			}
		}

		std::cout << "ResourcePool::GetResource(): The key \'" << name << "\' doesn't exist." << std::endl;
		return nullptr;
	}

private:
	/*
		pool is a vector of pairs. Each pair
		is a string containing the name we refer
		to when accessing the corresponding resource.
	*/
	std::vector<std::pair<std::string, T*>> pool;
};

#endif
