#include "ComponentPool.h"



ComponentPool::ComponentPool()
{
}


void ComponentPool::Clear(size_t size)
{
	m_EntitySparset.clear();

	for (int i = 0; i < m_Components.size(); i+= size)
	{
		BaseComponent* componet = (BaseComponent*)&m_Components[i];
		destroyComponent(componet);
	}
	m_Components.clear();
}

ComponentPool::~ComponentPool()
{
	//TODO::Deallocate memory
}
