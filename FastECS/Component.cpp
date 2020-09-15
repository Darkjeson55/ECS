#include "Component.h"
#include "World.h"

uint32_t BaseComponent::index = 0;
std::vector<size_t> BaseComponent::componentType;
uint32_t BaseComponent::registerComponentType(size_t size)
{ 
	componentType.push_back(size);
	World::resizeComp(componentType.size());
	return index++; 
};