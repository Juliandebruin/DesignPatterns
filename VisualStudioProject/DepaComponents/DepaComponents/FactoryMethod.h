#pragma once
#include <string>
#include <map>

class Component;

template<class TID, class TClass>
class FactoryMethod
{
public:
	FactoryMethod();
	virtual ~FactoryMethod();

	static void assign(TID id, TClass* instance);
	static TClass* create(TID id);

private:
	static std::map<TID, TClass*>& get_dictorionary();
};

#include "FactoryMethod.hpp"