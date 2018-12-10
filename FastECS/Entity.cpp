#include "Entity.h"



Entity::Entity()
{
	m_key.reset();
}


void Entity::addComponent(uint32_t ID)
{
	m_key[ID] = 1;
}

void Entity::removeComponent(uint32_t ID)
{
	m_key[ID] = 0;
}

std::bitset<150> Entity::getKey()
{
	return m_key;
}

void Entity::setID(uint32_t ID)
{
	m_EntityID = ID;
}

uint32_t Entity::getID()
{
	return m_EntityID;
}


Entity::~Entity()
{
}
