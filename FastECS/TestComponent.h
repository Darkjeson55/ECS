#pragma once

#include "ECS/Component.h"

struct TestComponent : public Component<TestComponent>
{
public:
	float x;
};
