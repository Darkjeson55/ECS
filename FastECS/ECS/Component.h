#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include "Entity.h"





struct BaseComponent
{
	EntityHandler* handler;
	static uint32_t registerComponentType();
private:
	static uint32_t index;

};

template<class T>
struct Component : public BaseComponent
{
	static const uint32_t ID;
	static const size_t SIZE;
};

template<class T>
const uint32_t Component<T>::ID(BaseComponent::registerComponentType());

template<class T>
const size_t Component<T>::SIZE(sizeof(T));



#endif

