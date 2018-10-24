#include "Entity.h"


Entity::Entity()
{
	m_component_Index.resize(150);
	std::fill(m_component_Index.begin(), m_component_Index.end(), -1);

	m_key.reset();
}


void Entity::addComponent(uint32_t ID, uint32_t index)
{

	m_component_Index[ID] = index;
	m_key[ID] = 1;
}

void Entity::removeComponent(uint32_t ID)
{
	m_component_Index[ID] = -1;
	m_key[ID] = 0;
}

uint32_t Entity::getComponentIndex(uint32_t ID)
{
	return m_component_Index[ID];
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
