#pragma once

#include<bitset>
#include<iostream>


class Entity
{
public:
	Entity();

	void addComponent(uint32_t ID);

	void removeComponent(uint32_t ID);

	std::bitset<150> getKey();

	void setID(uint32_t ID);

	uint32_t getID();

	~Entity();

private:

	uint32_t m_EntityID;
	std::bitset<150> m_key;
};