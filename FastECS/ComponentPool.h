#ifndef COMPONENTPOOL_H
#define	COMPONENTPOOL_H

#include "Component.h"
#include <vector>

class ComponentPool
{
public:
	ComponentPool();

	template<class T>
	void addComponent(uint32_t entityID)
	{
		uint32_t index = m_Components.size();
		m_Components.resize(index + T::SIZE);
		new(&m_Components[index])T(*(T*)new T());
		if (entityID >= m_EntitySparset.size())
		{
			m_EntitySparset.resize(entityID + 1);
		}
		m_EntitySparset[entityID] = index;
	}

	template<class T>
	T& getComponent(uint32_t entityID)
	{
		return (*(T*)&m_Components[m_EntitySparset[entityID]]);
	}


	template<class T>
	void removeComponent(uint32_t entitID)
	{
		//TODO:: RemoveComponent
	}


	~ComponentPool();
private:
	std::vector<uint32_t> m_EntitySparset;
	std::vector<uint32_t> m_EntityCompressed;
	std::vector<uint8_t> m_Components;
};

#endif
