#include <iostream>
#include <chrono>

#include "World.h"
#include "System.h"
#include "Component.h"
#include "ComponentPool.h"


using namespace std;
using namespace std::chrono;

struct Vector3f
{
	float x = 15;
	float y, z;
};

World world; 

struct Transform : public Component<Transform>
{
	Vector3f position;
};

struct Speed : public Component<Speed>
{
	Vector3f position;
};

class Moviment : public System
{
public:
	Moviment();

	void Update(uint32_t entity);

	~Moviment();

private:

};

Moviment::Moviment()
{
	registerComponent(Transform::ID);
	registerComponent(Speed::ID);
}

void Moviment::Update(uint32_t entity)
{
	auto component = world.getComponent<Transform>(entity);

	component->position.x += 5;

}

Moviment::~Moviment()
{
}

class Render : public System
{
public:
	Render();

	void Update(uint32_t entity);

	~Render();

private:

};

Render::Render()
{
	registerComponent(Transform::ID);
	registerComponent(Speed::ID);
}

void Render::Update(uint32_t entity)
{
	auto component = world.getComponent<Transform>(entity);
	auto component02 = world.getComponent<Speed>(entity);

	component->position.x += 5;
	component02->position.y = 12;
}

Render::~Render()
{
}


ComponentPool components;


int main()
{
	world.addSystem(new Moviment());
	world.addSystem(new Render());

	for (uint32_t i =0; i < 5; i++)
	{
		//components.addComponent<Transform>(i);
		auto entity = world.CreateEntity();
		world.addComponent<Transform>(entity);
		world.addComponent<Speed>(entity);
	}


	auto start = steady_clock::now();

	/*for (uint32_t i = 0; i < 5; i++)
	{
		auto comp = components.getComponent<Transform>(i);
		//std::cout << comp->position.x << std::endl;
	}*/
	world.UpdateSystems();
	auto end = steady_clock::now();



	

	auto clac = end - start;

	std::cout << duration_cast<milliseconds>(clac).count() << std::endl;


	system("PAUSE");

	return 0;
}