#pragma once

#include <unordered_map>
#include <typeindex>

class GameObject
{
public:
	static int id_counter;
	int id;
	std::unordered_map<std::type_index, void*> components;

	GameObject() : id(id_counter++) {}

	template<typename T> void add_component(T* component)
	{
		components[typeid(T)] = component;
	}

	template<typename T> T* get_component()
	{
		return static_cast<T*>(components[typeid(T)]);
	}
};


