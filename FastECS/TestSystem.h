#pragma once

#include "ECS/System.h"
#include "TestComponent.h"

class TestSystem : public System
{
public:
	TestSystem();

	void Update(BaseComponent** comp);

	~TestSystem();
};

