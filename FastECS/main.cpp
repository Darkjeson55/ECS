#include <iostream>
#include <chrono>


#include <vector>
#include <tuple>

using namespace std;
using namespace std::chrono;

struct Vector3f
{
	float x, y, z;
};


struct Transform
{
	Vector3f position;
};

struct Entity
{
	Entity()
	{
		m_components.resize(150);

	}


	void addComponent(uint32_t ID, uint32_t index)
	{
		m_components[ID] = index;
	}


	inline uint32_t getComponent(const uint32_t ID) { return m_components[ID]; }



};




	std::vector<uint32_t> m_components;
std::vector<uint8_t> Components;
std::vector<Entity> m_Entity;


int main()
{

	for (uint32_t i =0; i < 1000000; i++)
	{
		m_Entity.push_back(Entity());

		std::vector<uint8_t>& memory = Components;
		uint32_t index = memory.size();
		memory.resize(index + sizeof(Transform));
		new(&memory[index])Transform(*(Transform*)new Transform());
		Entity& entity = m_Entity.back();
		entity.addComponent(0, index);
	}


	auto start = steady_clock::now();
	for (uint32_t i = 0; i < m_Entity.size(); i+=1)
	{
		Transform* comp = (Transform*)&Components[m_Entity[i].getComponent(0)];

		comp->position.x += 5;
		comp->position.y += 5;
		comp->position.z += 5;
	}


	auto end = steady_clock::now();





	auto clac = end - start;

	std::cout << duration_cast<milliseconds>(clac).count() << std::endl;


	system("PAUSE");

	return 0;
}