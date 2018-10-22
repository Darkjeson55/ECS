#include <iostream>
#include <chrono>


#include "ECS/World.h"
#include "TestSystem.h"
#include "TestComponent.h"

#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

struct Transform : Component<Transform>
{
	float x;
};


std::vector<uint8_t> memory;

std::vector<BaseComponent*> components;
std::vector<Transform> components02;

template<class T>
void addComponent(std::vector<uint8_t>& memory, T* comp)
{
	uint32_t index = memory.size();
	memory.resize(index + T::SIZE);
	T* component = new(&memory[index])T(*(T*)comp);
}

int main()
{
	
	for (uint32_t i = 0; i < 5000000; i++)
	{
		addComponent(memory, new Transform());
	}
	for (uint32_t i = 0; i < 5000000; i++)
	{
		components.emplace_back(std::move(new Transform()));
	}
	for (uint32_t i = 0; i < 5000000; i++)
	{
		components02.emplace_back();
	}




	auto start = steady_clock::now();
	for (uint32_t i = 0; i < memory.size(); i += Transform::SIZE)
	{
		Transform* comp = (Transform*)&memory[i];

		comp->x += 5;

		//std::cout << comp->x << std::endl;

	}
	auto end = steady_clock::now();

	auto start01 = steady_clock::now();
	for (uint32_t i = 0; i < components.size(); i++)
	{
		Transform* comp = (Transform*)&components[i];

		comp->x += 5;

		//std::cout << comp->x << std::endl;

	}
	auto end01 = steady_clock::now();


	auto start02 = steady_clock::now();
	for (uint32_t i = 0; i < components02.size(); i++)
	{
		Transform& comp = components02[i];

		comp.x += 5;

		//std::cout << comp->x << std::endl;

	}
	auto end02 = steady_clock::now();






	auto clac = end - start;
	auto clac01 = end01 - start01;
	auto clac02 = end02 - start02;
	std::cout << duration_cast<milliseconds>(clac).count() << std::endl;
	std::cout << duration_cast<milliseconds>(clac01).count() << std::endl;
	std::cout << duration_cast<milliseconds>(clac02).count() << std::endl;


	/*World::addGameSystem(new TestSystem());


	for (uint32_t i = 0; i < 5; i++)
	{
		auto entity = World::CreateEntity();
		entity->add_Component<TestComponent>();
	}




	auto start = steady_clock::now();
	World::UpdateGameSystems();
	auto end = steady_clock::now();
	

	auto clac = end - start;
	std::cout << duration_cast<milliseconds>(clac).count() << std::endl;*/



	system("PAUSE");

	return 0;
}