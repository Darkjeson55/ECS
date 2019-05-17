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

void World::removeEntityFromSystem(Entity* entity)
{
	for (int i = 0; i < m_Systems.size(); i++)
	{
		if ((m_Systems[i]->getSystemKey() &  entity->getKey()) != m_Systems[i]->getSystemKey())
		{
			m_Systems[i]->removeEntity(entity->getID());
		}
	}
}

void World::RemoveEntity(Entity* entity)
{
	removeEntityFromSystem(entity);
	m_Entitys.erase(std::remove(m_Entitys.begin(), m_Entitys.end(), entity), m_Entitys.end());
}

void World::addSystem(System* system)
{
	m_Systems.push_back(system);
}

void World::removeSystem(System* system)
{

	m_Systems.erase(std::remove(m_Systems.begin(), m_Systems.end(), system), m_Systems.end());

	//TODO:: 
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
	for (int i = 0; i < m_Systems.size(); i++)
	{
		m_Systems[i]->Clear();
	}

	for (int i = 0; i < m_Entitys.size(); i++)
	{
		delete(m_Entitys[i]);
	}

	for (int i = 0; i < m_Components.size(); i++)
	{
		m_Components[i].Clear(BaseComponent::getTypeSize(i));
	}
}
