#include <iostream>
#include <chrono>


#include "ECS/World.h"
#include "TestSystem.h"
#include "TestComponent.h"

#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

struct Entitys
{
	virtual void Update() {}
};

struct Player : public Entitys
{
	void Update() {
		x += 5;
	}

	float x;
};


std::vector<Entitys*> m_Entity;



int main()
{
	World::addGameSystem(new TestSystem());


	for (uint32_t i = 0; i < 1000000; i++)
	{
		auto entity = World::CreateEntity();
		entity->add_Component<TestComponent>();
	}

	



	auto start = steady_clock::now();
	World::UpdateGameSystems();
	auto end = steady_clock::now();

	

	auto clac = end - start;
	//auto clac01 = end01 - start01;

	std::cout << duration_cast<milliseconds>(clac).count() << std::endl;
	//std::cout << duration_cast<milliseconds>(clac01).count() << std::endl;



	system("PAUSE");

	return 0;
}