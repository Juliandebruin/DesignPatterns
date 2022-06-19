#pragma once

#include "AND.h"
#include <iostream>

AND AND::m_cInstance( 3 );

AND::AND()
{
}

AND::AND(int id): Components(id)
{
}

Components* AND::clone() const
{
    return new AND;
}


AND::~AND()
{
}

void AND::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input[0] * _input[1];
    //PrintInfo();
    Sleep(propegation_delay_ms);
    Notify();
}

void AND::PrintInfo()
{
    std::cout << "Observer AND updated\n";
}
