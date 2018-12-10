#ifndef WORLD_H
#define	WORLD_H

#include <unordered_map>
#include <map>


#include "ComponentPool.h"
#include "Component.h"
#include "System.h"
#include "Entity.h"



class World
{
public:
	World();

	Entity* CreateEntity();
	void RemoveEntity();

	template<class T> 
	void addComponent(Entity* entity)
	{
		m_Components[T::ID].addComponent<T>(entity->getID());
		entity->addComponent(T::ID);
		checkEntityToSystem(entity);
	}

	template<class T>
	T* getComponent(uint32_t entityID)
	{
		return &m_Components[T::ID].getComponent<T>(entityID);
	}


	void checkEntityToSystem(Entity* entity);
	void removeComponent();

	void addSystem(System* system);
	void removeSystem();

	void UpdateSystems();

	~World();

private:

	std::vector<Entity*> m_Entitys;
	std::vector<System*> m_Systems;

	std::map<uint32_t, ComponentPool> m_Components;



};

#endif
