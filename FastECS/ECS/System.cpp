#include "System.h"



System::System()
{
}


void System::UpdateComponents()
{
	for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		BaseComponent* components = &(BaseComponent&)it;
		Update(&components);
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
