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


	std::vector<uint32_t>& getComponentTypes()
	{
		return ComponentTypes;
	}

	std::bitset<1024>& getSystemKey()
	{
		return m_key;
	}

	~System();
	
protected:
	void registerComponent(uint32_t ID);
private:
	std::bitset<1024> m_key;
	std::vector<uint32_t> ComponentTypes;
	std::unordered_map<uint32_t, std::vector<BaseComponent*>> Entitys;


};

