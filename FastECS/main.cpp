#include <iostream>
#include <chrono>


#include "ECS/World.h"
#include "TestSystem.h"
#include "TestComponent.h"

#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

struct Transform
{
	float x;
};


int main()
{
	World::addGameSystem(new TestSystem());


	for (uint32_t i = 0; i < 5; i++)
	{
		auto entity = World::CreateEntity();
		entity->add_Component<TestComponent>();
	}




	auto start = steady_clock::now();
	World::UpdateGameSystems();
	auto end = steady_clock::now();
	

	auto clac = end - start;
	std::cout << duration_cast<milliseconds>(clac).count() << std::endl;



	system("PAUSE");

	return 0;
}