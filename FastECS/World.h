#ifndef WORLD_H
#define	WORLD_H

#include <unordered_map>
#include <map>
#include <algorithm>


#include "ComponentPool.h"
#include "Component.h"
#include "System.h"
#include "Entity.h"

class World;

struct EntityHandler
{
	template<class T, class... Args>
	void add_Component(Args... args)
	{
		World::addComponent(this, new T(args...));
	}
};



class World
{
public:
	World();

	Entity* CreateEntity();
	void RemoveEntity(Entity* entity);

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

	template<class Component>
	void removeComponent(Entity* entity)
	{
		entity->removeComponent(Component::ID);	
		m_Components[Component::ID].removeComponent<Component>(entity->getID());

		removeEntityFromSystem(entity);
	}

	void removeEntityFromSystem(Entity* entity);


	void addSystem(System* system);
	void removeSystem(System* system);

	void UpdateSystems();

	~World();

private:

	std::vector<Entity*> m_Entitys;
	std::vector<System*> m_Systems;

	std::map<uint32_t, ComponentPool> m_Components;



};

#endif
