#pragma once

#include "Components.h"
#include "FactoryMethod.h"
#include <iostream>

Components::Components() :
    _name("")
{
}

Components::Components(int id) :
    _name("")
{
    Factory::FactoryMethod<int, Components>::assign(id, this);
}

Components::~Components()
{
}

void Components::set_list(Components& subject)
{
    this->Attach(&subject, subject._number_of_listeners);
    subject._number_of_listeners++;
}

void Components::RemoveMeFromTheList()
{
    subject_.Detach(this);
}

void Components::set_name(string name)
{
    _name = name;
}

string Components::get_name()
{
    return _name;
}

string Components::get_type()
{
    return _type;
}

void Components::set_type(string type)
{
    _type = type;
}
