#ifndef WORLD_HEADER
#define WORLD_HEADER


#include <vector>
#include <map>
#include <unordered_map>

//external Includes
#include <tuple>
#include <utility>
#include <bitset>


//internal Includes
#include "Component.h"
#include "Entity.h"
#include "System.h"


class World
{
public:
	World();
	~World();
	
	
	static EntityHandler* CreateEntity();

	static void removeEntity(EntityHandler* handler);

	template<class T>
	static void addComponent(EntityHandler* handler, T* Component)
	{
		std::vector<BaseComponent>& memory = m_components[T::ID];
		memory.emplace_back(*Component);


		std::pair<ComponentType, ComponentID> pair;
		pair.first = T::ID;
		pair.second = memory.size();
		std::get<1>(*HandleToRow(handler)).emplace_back(pair);
		std::get<2>(*HandleToRow(handler))[T::ID] = 1;

		auto EnttKey = std::get<2>(*HandleToRow(handler));

		for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
		{

			System* gameSystem = m_Game_Systems[i];

			std::bitset<1024>& systKey = gameSystem->getSystemKey();

			if ((EnttKey & systKey) == systKey)
			{
				auto componentTypes = gameSystem->getComponentTypes();

				std::vector<BaseComponent*> m_components;
				for (uint32_t x = 0; x < componentTypes.size(); x++)
				{
					m_components.emplace_back( getComponentByID(componentTypes[x], handler));
				}


				gameSystem->addEntity(std::get<0>(*HandleToRow(handler)), m_components);

			}
			
		}
	}

	template<class T>
	static void removeComponent(EntityHandler* handler)
	{
		for (uint32_t i = 0; i < HandleToRow(handler)->second.size(); i++)
		{
			if (T::ID == HandleToRow(handler)->second[i].first)
			{
				m_components[T::ID].erase(HandleToRow(handler)->second[i].second);
				HandleToRow(handler)->second.erase(HandleToRow(handler)->second.begin() + i);


				for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
				{
					m_Game_Systems[i]->deregisterEntity(handler);
				}
			}
		}
	}

	template<class T>
	static T* getComponentInternal(EntityHandler* handler)
	{
		for (uint32_t i = 0; i < std::get<1>(*HandleToRow(handler)).size(); i++)
		{
			if (T::ID == std::get<1>(*HandleToRow(handler))[i].first)
			{
				return (T*)m_components[T::ID][std::get<1>(*HandleToRow(handler))[i].second];
			}
		}

		return nullptr;
	}





	static BaseComponent* getComponentByID(uint32_t ID, EntityHandler* handler);



	static void addGameSystem(System* system);
	static void removeGameSystem(System* system);

	static void UpdateGameSystems();


private:
	static std::vector<System*> m_Game_Systems;

	static std::vector<Entity*> m_Entitys;
	//static std::map<uint32_t,std::vector<uint8_t>> m_components;
	static std::unordered_map<uint32_t, std::vector<BaseComponent>> m_components;

	static inline Entity* HandleToRow(EntityHandler* entity)
	{
		return (Entity*)entity;
	}
};



#endif
