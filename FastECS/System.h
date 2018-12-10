#ifndef SYSTEM_H
#define	SYSTEM_H

#include <bitset>
#include <vector>


#include "Entity.h"

class System
{
public:
	System();


	virtual void Update(uint32_t entity) {}

	void UpdateComponents();

	void addEntity(uint32_t entity_ID);

	void removeEntity(uint32_t entity_ID);

	void Clear();

	void registerComponent(uint32_t ID);


	std::vector<uint32_t>& getComponentTypes()
	{
		return m_ComponentTypes;
	}

	std::bitset<150>& getSystemKey()
	{
		return m_key;
	}

	~System();
private:
	std::bitset<150> m_key;
	std::vector<uint32_t> m_ComponentTypes;
	std::vector<uint32_t> m_Entity;
};


#endif
