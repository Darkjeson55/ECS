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
	
	
	template<class T>
	static void addComponent(T* Component)
	{
		memory.emplace_back(Component);
	}


	static void Update();


private:
	//static std::vector<System*> m_Game_Systems;

	//static std::vector<Entity*> m_Entitys;
	//static std::map<uint32_t,std::vector<uint8_t>> m_components;
	//static std::unordered_map<uint32_t, std::vector<BaseComponent*>> m_components;

	static std::vector<BaseComponent*> memory;



};



#endif
