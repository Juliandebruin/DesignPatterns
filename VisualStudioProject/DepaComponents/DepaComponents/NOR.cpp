#include "NOR.h"
#include <iostream>

NOR NOR::_instance("NOR");

NOR::NOR()
{
}

NOR::NOR(string componentName) :
    Components(componentName)
{
}

NOR::~NOR()
{
}

void NOR::update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - (_input[0] + _input[1]);
    Sleep(propegation_delay_ms);
    notify();
}

void NOR::PrintInfo()
{
    std::cout << "Observer NOR updated\n";
}

Components* NOR::clone()
{
    return new NOR;
}
