#include "NOT.h"

#include <iostream>

NOT NOT::m_cInstance(5);

NOT::NOT()
{
}

NOT::NOT(int id) : Components(id)
{
}


Components* NOT::clone() const
{
    return new NOT;
}


NOT::~NOT()
{
}

void NOT::Update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - _input[0];
    //PrintInfo();
    Sleep(propegation_delay_ms);
    Notify();
}

void NOT::PrintInfo()
{
    std::cout << "Observer NOT updated\n";
}
