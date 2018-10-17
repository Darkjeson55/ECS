#include "System.h"



System::System()
{
}


void System::UpdateComponents()
{
	for (auto it = Entitys.begin(); it != Entitys.end(); ++it)
	{
		BaseComponent* components = &(BaseComponent&)it->first;
		Update(&components);
	}
}

void System::addEntity(uint32_t entity_ID, std::vector<BaseComponent*> components)
{
	//std::cout << entity_ID << std::endl;
	Entitys[entity_ID] = components;

	//td::cout << Entitys.size() << std::endl;

}

void System::registerComponent(uint32_t ID)
{


	ComponentTypes.emplace_back(ID);
	m_key[ID] = 1;
}

System::~System()
{
}
