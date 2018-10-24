#pragma once

#include<tuple>
#include<vector>
#include<bitset>
#include<iostream>

using ComponentType = uint32_t;
using ComponentID = uint32_t;
using EntityID = uint32_t;


//using Entity = std::tuple<EntityID, std::vector<std::pair<ComponentType, ComponentID>>, std::bitset<1024>>;


struct EntityHandler
{
	template<class T, class... Args>
	void add_Component(Args... args)
	{
		World::addComponent(this, new T(args...));
	}
};


class Entity
{
public:
	Entity();

	void addComponent(uint32_t ID, uint32_t index);

	void removeComponent(uint32_t ID);

	uint32_t getComponentIndex(uint32_t ID);

	std::bitset<150> getKey();

	void setID(uint32_t ID);

	uint32_t getID();

	~Entity();

private:

	uint32_t m_EntityID;
	std::bitset<150> m_key;
	std::vector<int> m_component_Index;

};