#include "NOT.h"
#include <iostream>

NOT NOT::_instance("NOT");

NOT::NOT()
{
}

NOT::NOT(string componentName) :
    Components(componentName)
{
}

NOT::~NOT()
{
}

void NOT::Update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - _input[0];
    Sleep(propegation_delay_ms);
    Notify();
}

void NOT::PrintInfo()
{
    std::cout << "Observer NOT updated\n";
}

Components* NOT::clone()
{
    return new NOT;
}