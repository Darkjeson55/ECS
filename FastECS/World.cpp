#include "World.h"



World::World()
{
}

Entity* World::CreateEntity()
{
	uint32_t index = m_Entitys.size();
	m_Entitys.emplace_back(new Entity());
	Entity* newEntity = m_Entitys.back();
	newEntity->setID(index);
	return newEntity;
}


void World::checkEntityToSystem(Entity* entity)
{
	for (int i = 0; i < m_Systems.size(); i++)
	{
		if ((entity->getKey() & m_Systems[i]->getSystemKey()) == m_Systems[i]->getSystemKey())
		{
			m_Systems[i]->addEntity(entity->getID());
		}
	}
}

void World::RemoveEntity()
{

}
void World::removeComponent()
{

}

void World::addSystem(System* system)
{
	m_Systems.push_back(system);
}
void World::removeSystem()
{

}



void World::UpdateSystems()
{
	for (int i = 0; i < m_Systems.size(); i++)
	{
		m_Systems[i]->UpdateComponents();
	}
}

World::~World()
{
}
