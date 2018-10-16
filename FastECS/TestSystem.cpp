#include "TestSystem.h"



TestSystem::TestSystem()
{

	registerComponent(TestComponent::ID);

}

void TestSystem::Update(BaseComponent** comp)
{
	TestComponent* TestCompo = &(TestComponent&)comp[0];

	TestCompo->x += 5.0f;
}


TestSystem::~TestSystem()
{
}
