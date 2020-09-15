#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <vector>


struct BaseComponent
{
	static uint32_t registerComponentType(size_t size);


	inline static size_t getTypeSize(uint32_t id)
	{
		return componentType[id];
	}

	inline static size_t getTypeListSize()
	{
		return componentType.size();
	}

	uint32_t entityIndex;
private:
	static uint32_t index;	
	static std::vector<size_t> componentType;
};



template<class T>
struct Component : public BaseComponent
{
	static const uint32_t ID;
	static const size_t SIZE;
};



template<class T>
const size_t Component<T>::SIZE(sizeof(T));

template<class T>
const uint32_t Component<T>::ID(BaseComponent::registerComponentType(T::SIZE));


#endif

