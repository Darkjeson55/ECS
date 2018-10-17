#include"World.h"

std::unordered_map<uint32_t, std::vector<BaseComponent>> World::m_components;
std::vector<System*> World::m_Game_Systems;
std::vector<Entity*> World::m_Entitys;

World::World()
{

}


EntityHandler* World::CreateEntity()
{
	uint32_t index = m_Entitys.size();
	m_Entitys.emplace_back(new Entity());
	Entity* newEntity = m_Entitys.back();
	std::get<2>(*newEntity).reset();
	std::get<0>(*newEntity) = index;
	EntityHandler* Handler = (EntityHandler*)newEntity;
	return Handler;
}

void World::removeEntity(EntityHandler* handler)
{
	Entity* entity = HandleToRow(handler);

	/*for (uint32_t i = 0; i < std::get<1>(*entity).size(); i++)
	{
		m_components[std::get<1>(*entity)[i].first].erase(m_components[std::get<1>(*entity)[i].first].begin() + std::get<1>(*entity)[i].second);
		std::get<1>(*entity).erase(std::get<1>(*entity).begin() + i);
	}

	m_Entitys.erase(m_Entitys.begin() + std::get<0>(*entity));
	delete(entity);*/
}

void World::UpdateGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		/*if (m_Game_Systems[i]->getComponentTypes().size() == 1)
		{
			System* sys = m_Game_Systems[i];
			std::vector<BaseComponent>& comp = m_components[sys->getComponentTypes()[0]];

			for (int x = 0; x < comp.size(); x++)
			{
				BaseComponent* tempComponent = &(BaseComponent&)comp[x];
				sys->Update(&tempComponent);
			}

		}
		else
		{
		}*/

		m_Game_Systems[i]->UpdateComponents();


	}
}


void World::addGameSystem(System* system)
{
	m_Game_Systems.push_back(system);

	if (m_Entitys.size() > 0)
	{
		for (uint32_t i = 0; i < m_Entitys.size(); i++)
		{
					
		}
	}

}
 

BaseComponent* World::getComponentByID(uint32_t ID, EntityHandler* handler)
{

	for (uint32_t i = 0; i < std::get<1>(*HandleToRow(handler)).size(); i++)
	{
		if (ID == std::get<1>(*HandleToRow(handler))[i].first)
		{
			return &m_components[ID][std::get<1>(*HandleToRow(handler))[i].second];
		}
	}
}


void World::removeGameSystem(System* system)
{

}


World::~World()
{
	
}