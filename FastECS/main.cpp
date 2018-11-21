#include <iostream>
#include <chrono>


#include "ECS/Component.h"
#include "ECS/Entity.h"
//
//#include "ECS/World.h"
//#include "TestSystem.h"
//#include "TestComponent.h"

#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;


struct Registry
{

};


struct System
{
	virtual void Update();
};

struct MovimentSystem : public System
{

};



std::vector<Entity*> Entitys;
std::vector<System*> Systems;
std::unordered_map<uint32_t, std::vector<uint8_t>> Components;

Entity* CreateEntity()
{
	uint32_t index = Entitys.size();
	Entitys.emplace_back(new Entity());
	Entity* newEntity = Entitys.back();
	newEntity->setID(index);
	return newEntity;
}

template<class T>
void addComponent(Entity* e, T* component)
{
	std::vector<uint8_t>& memory = Components[T::ID];
	uint32_t index = memory.size();
	memory.resize(index + T::SIZE);
	new(&memory[index])T(*((T*)component));
	e->addComponent(T::ID, index);
}


int main()
{




	/*World::addGameSystem(new TestSystem());

	for (int i = 0; i<1000000; i++)
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