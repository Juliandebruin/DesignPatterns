#pragma once

#include "AND.h"
#include <iostream>

AND AND::m_cInstance( 3 );

AND::AND()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

AND::AND(int id): Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


Components* AND::clone() const
{
    return new AND;
}


AND::~AND()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void AND::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input[0] * _input[1];
    //PrintInfo();
    Notify();
}

void AND::PrintInfo()
{
    std::cout << "Observer AND updated\n";
}
