#pragma once

#include<tuple>
#include<vector>
#include<bitset>

using ComponentType = uint32_t;
using ComponentID = uint32_t;
using EntityID = uint32_t;


using Entity = std::tuple<EntityID, std::vector<std::pair<ComponentType, ComponentID>>, std::bitset<1024>>;


struct EntityHandler
{
	template<class T, class... Args>
	void add_Component(Args... args)
	{
		T* component = new T(args...);
		World::addComponent(this, component);
	}
};