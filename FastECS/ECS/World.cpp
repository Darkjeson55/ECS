#include"World.h"
#include "../TestComponent.h"

//std::unordered_map<uint32_t, std::vector<BaseComponent*>> World::m_components;
std::vector<BaseComponent*> World::memory;
World::World()
{

}


void World::Update()
{
	for (uint32_t i = 0; i < memory.size(); i++)
	{
		std::cout << "Component position " << static_cast<TestComponent*>(memory[i])->x << std::endl;
	}
}


World::~World()
{
	for (uint32_t i = 0; i < memory.size(); i++)
	{
		delete(memory[i]);
		memory.erase(memory.begin() + i);
	}
}