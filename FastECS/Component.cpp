#include "Component.h"



uint32_t BaseComponent::index = 0;
uint32_t BaseComponent::registerComponentType() { return index++; };