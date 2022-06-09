#pragma once

#include "Output.h"
#include <iostream>

Output Output::m_cInstance(2);

Output::Output()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

Output::Output(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}

void Output::PrintInfo()
{
    std::cout << "Observer" << "output " << output << "\n";
}

Components* Output::clone() const
{
    return new Output;
}

Output::~Output()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void Output::Update(bool output, int index)
{
    _input[0] = output;
    _output = _input[0];
    PrintInfo();
    Notify();
}
