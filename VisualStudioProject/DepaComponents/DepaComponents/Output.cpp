#pragma once

#include "Output.h"
#include <iostream>

Output Output::m_cInstance(2);

Output::Output()
{
}

Output::Output(int id) : Components(id)
{
}

void Output::PrintInfo()
{
    std::cout << "Observer" << "output " << _output << "\n";
}

Components* Output::clone() const
{
    return new Output;
}

Output::~Output()
{
}

void Output::Update(bool output, int index)
{
    _input[0] = output;
    _output = _input[0];
    //PrintInfo();
    Notify();
}