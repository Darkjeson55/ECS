#include "System.h"



System::System()
{
}


void System::UpdateComponents()
{
	for (uint32_t i = 0; i < m_Components.size(); i++)
	{
		std::vector<BaseComponent*>& components = m_Components[i];
		Update(&components[0]);
	}
}

void System::addEntity(uint32_t entity_ID, std::vector<BaseComponent*> components)
{
	m_Entitys[entity_ID] = m_Components.size();
	m_Components.emplace_back(components);
}

void System::removeEntity(uint32_t entity_ID)
{
	m_Components.erase(m_Components.begin() + m_Entitys[entity_ID]);
	m_Entitys.erase(entity_ID);
}


void System::registerComponent(uint32_t ID)
{
	m_ComponentTypes.emplace_back(ID);
	m_key[ID] = 1;
}

System::~System()
{
}
