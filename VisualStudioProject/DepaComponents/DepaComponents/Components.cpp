#pragma once

#include "Components.h"
#include "FactoryMethod.h"
#include <iostream>

Components::Components() :
    _name(""), propegation_delay_ms(0), subject_( *this)
{
}

Components::Components(string componentName) :
    _name(""), propegation_delay_ms(0), subject_(*this)
{
    FactoryMethod<std::string, Components>::assign(componentName, this);
}

Components::~Components()
{
}

void Components::set_list(Components& subject)
{
    this->attach(&subject, subject._number_of_listeners);
    subject._number_of_listeners++;
}

void Components::remove_from_list()
{
    subject_.detach(this);
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
