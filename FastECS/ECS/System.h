#pragma once

#include "Component.h"
#include <vector>
#include <unordered_map>
#include <bitset>

class System
{
public:
	System();

	virtual void Update(BaseComponent** components) {}

	void UpdateComponents();

	void addEntity(uint32_t entity_ID, std::vector<BaseComponent*> components);

	void removeEntity(uint32_t entity_ID);

	void Clear();


	std::vector<uint32_t>& getComponentTypes()
	{
		return m_ComponentTypes;
	}

	std::bitset<150>& getSystemKey()
	{
		return m_key;
	}

	~System();
	
protected:
	void registerComponent(uint32_t ID);
private:
	std::bitset<150> m_key;
	std::vector<uint32_t> m_ComponentTypes;
	std::vector<std::vector<BaseComponent*>> m_Components;
	std::unordered_map<uint32_t, uint32_t> m_Entitys;


};

