#pragma once

#include "OR.h"
#include <iostream>

OR OR::m_cInstance(4);

OR::OR()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

OR::OR(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


void OR::Update(bool output, int index)
{
    _input[index] = output;
    _output = (_input[0] + _input[1]) ;
    //PrintInfo();
    Notify();
}

void OR::PrintInfo()
{
    std::cout << "Observer OR updated\n";
}

Components* OR::clone() const
{
    return new OR;
}

OR::~OR()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}