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

#include "../TestComponent.h"


class World
{
public:
	World();
	~World();
	

	static EntityHandler* CreateEntity();
	static void RemoveEntity(EntityHandler* handler);

	template<class T>
	static void addComponent(EntityHandler* entity,T* Component)
	{
		std::vector<BaseComponent*>& memory = m_components[T::ID];
		uint32_t index = memory.size();
		memory.emplace_back(Component);

		HandlerToRow(entity)->addComponent(T::ID, index);

		addEntityToSystems(entity);
	}
	
	template<class T>
	void RemoveComponet(EntityHandler* entity)
	{

	}

	static void addEntityToSystems(EntityHandler* handler);
	static void removeEntityToSystems(EntityHandler* handler);

	static void addGameSystem(System* system);
	static void removeGameSystem(System* system);
	
	static void addEngineSystem(System* system);
	static void removeEgnineSystem(System* system);

	static void UpdateGameSystems();
	static void UpdateEngineSystems();



private:

	static inline Entity* HandlerToRow(EntityHandler* handler)
	{
		return (Entity*)handler;
	}


	static std::vector<System*> m_Game_Systems;
	static std::vector<System*> m_Engine_Systems;
	static std::vector<Entity*> m_Entitys;
	static std::unordered_map<uint32_t, std::vector<BaseComponent*>> m_components;
};



#endif
