#include "TestSystem.h"



TestSystem::TestSystem()
{

	registerComponent(TestComponent::ID);

}

void TestSystem::Update(BaseComponent** comp)
{
	TestComponent* TestCompo = (TestComponent*)&comp[0];
	//std::cout <<  TestCompo->x << std::endl;
}


TestSystem::~TestSystem()
{
}
