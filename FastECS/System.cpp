#include "System.h"



System::System()
{
}


void System::UpdateComponents()
{
	for (uint32_t i = 0; i < m_Entity.size(); i++)
	{
		Update(m_Entity[i]);
	}
}

void System::addEntity(uint32_t entity_ID)
{
	m_Entity.emplace_back(entity_ID);
}

void System::removeEntity(uint32_t entity_ID)
{
	for (uint32_t i = 0; i < m_Entity.size(); i++)
	{
		if (m_Entity[i] == entity_ID)
		{
			m_Entity.erase(m_Entity.begin() + i);
		}
	}
}

void System::registerComponent(uint32_t ID)
{
	m_ComponentTypes.emplace_back(ID);
	m_key[ID] = 1;
}


void System::Clear()
{

}


System::~System()
{
}
