#pragma once

#include "Components.h"
#include "FactoryMethod.h"
#include <iostream>

Components::Components() :
    _name("")
{
   //std::cout << "in default constructor Basis" << std::endl;
}

Components::Components(int id) :
    _name("")
{
    Factory::FactoryMethod<int, Components>::assign(id, this);

   // std::cout << "in assignment constructor Basis" << std::endl;
}

Components::~Components()
{
}

void Components::set_list(Components& subject)
{
    //subject_ = subject;
    this->Attach(&subject, subject._number_of_listeners);
    subject._number_of_listeners++;
}

void Components::RemoveMeFromTheList()
{
    subject_.Detach(this);
    std::cout << "Observer \"" <<  "\" removed from the list.\n";
}

void Components::set_name(string name)
{
    _name = name;
}

string Components::get_name()
{
    return _name;
}
