#include "FactoryMethod.h"
#pragma once

template<class TID, class TClass>
inline FactoryMethod<TID, TClass>::FactoryMethod()
{
}

template<class TID, class TClass>
inline FactoryMethod<TID, TClass>::~FactoryMethod()
{
}

template<class TID, class TClass>
inline void FactoryMethod<TID, TClass>::assign(TID id, TClass* instance)
{
	if (get_dictorionary().find(id) == get_dictorionary().end()) {
		get_dictorionary().insert({ id, instance });
	}
}

template<class TID, class TClass>
inline TClass* FactoryMethod<TID, TClass>::create(TID id)
{
	if (get_dictorionary().find(id) != get_dictorionary().end()) {
		return get_dictorionary().find(id)->second->clone();
	}
	else {
		return nullptr;
	}
}

template<class TID, class TClass>
inline std::map<TID, TClass*>& FactoryMethod<TID, TClass>::get_dictorionary()
{
	static std::map<TID, TClass*> _dictionairy;
	return _dictionairy;
}
