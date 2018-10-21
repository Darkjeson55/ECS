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

	auto EnttKey = getEntityComponentKey(handler);

	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		System* gameSystem = m_Game_Systems[i];
		std::bitset<1024>& systKey = gameSystem->getSystemKey();
		if ((EnttKey & systKey) == systKey)
		{
			m_Game_Systems[i]->removeEntity(getEntityID(handler));
		}
	}


	for (uint32_t i = 0; i < getEntityComponentList(handler).size(); i++)
	{
		auto ComponentList = m_components[getEntityComponentList(handler)[i].first];
		removeComponentInternal(ComponentList, getEntityComponentList(handler)[i].second, getEntityComponentList(handler)[i].first);
	}

	m_Entitys.erase(m_Entitys.begin() + getEntityID(handler));

	delete(entity);
}



void World::removeComponentInternal(std::vector<BaseComponent>& memory, uint32_t Componentindex, uint32_t EntityComponentID)
{
	if (Componentindex != memory.size() - 1)
	{
		BaseComponent& compoent = memory[memory.size() - 1];
		memory[Componentindex] = std::move(compoent);

		for (uint32_t i = 0; i < getEntityComponentList(compoent.handler).size(); i++)
		{
			if (EntityComponentID == getEntityComponentList(compoent.handler)[i].first)
			{
				getEntityComponentList(compoent.handler)[i].second = Componentindex;
			}
		}
		memory.pop_back();
	}
	else
	{
		memory.erase(memory.begin() + Componentindex);
	}

}


void World::UpdateGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		if (m_Game_Systems[i]->getComponentTypes().size() == 1)
		{
			std::vector<BaseComponent>& comp = m_components[m_Game_Systems[i]->getComponentTypes()[0]];

			for (int x = 0; x < comp.size(); x++)
			{
				BaseComponent* tempComponent = (BaseComponent*)&comp[x];
				m_Game_Systems[i]->Update(&tempComponent);
			}

		}
		else
		{
			m_Game_Systems[i]->UpdateComponents();
		}
	}
}


void World::addGameSystem(System* system)
{
	m_Game_Systems.push_back(system);

	auto sysKey = system->getSystemKey();

	if (m_Entitys.size() > 0)
	{
		for (uint32_t i = 0; i < m_Entitys.size(); i++)
		{
			auto EntityKey = std::get<2>(*m_Entitys[i]);


			if ((EntityKey & sysKey) == sysKey)
			{
				auto componentTypes = system->getComponentTypes();

				std::vector<BaseComponent*> m_components;
				for (uint32_t x = 0; x < componentTypes.size(); x++)
				{
					m_components.emplace_back(getComponentByID(componentTypes[x], m_Entitys[i]));
				}


				system->addEntity(std::get<0>(*m_Entitys[i]), m_components);

			}
		}
	}

}
 

BaseComponent* World::getComponentByID(uint32_t ID, EntityHandler* handler)
{

	for (uint32_t y = 0; y < getEntityComponentList(handler).size(); y++)
	{
		if (ID == getEntityComponentList(handler)[y].first)
		{
			std::vector<BaseComponent>& array = m_components[ID];
			return &array[getEntityComponentList(handler)[y].second];
		}
	}
}

BaseComponent* World::getComponentByID(uint32_t ID, Entity* handler)
{
	for (uint32_t i = 0; i < std::get<1>(*handler).size(); i++)
	{
		if (ID == std::get<1>(*handler)[i].first)
		{
			return &m_components[ID][std::get<1>(*handler)[i].second];
		}
	}
}



void World::removeGameSystem(System* system)
{

}


World::~World()
{
	for (uint32_t i = 0; i < m_Entitys.size(); i++)
	{
		delete m_Entitys[i];
	}

	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		delete m_Game_Systems[i];
	}
	m_Game_Systems.clear();
	m_Entitys.clear();
}