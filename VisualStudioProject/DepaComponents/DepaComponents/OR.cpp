#include "OR.h"
#include <iostream>

OR OR::_instance("OR");

OR::OR()
{
}

OR::OR(string componentName): 
    Components(componentName)
{
}

OR::~OR()
{
}

void OR::Update(bool output, int index)
{
    _input[index] = output;
    _output = (_input[0] + _input[1]) ;
    Sleep(propegation_delay_ms);
    Notify();
}

void OR::PrintInfo()
{
    std::cout << "Observer OR updated\n";
}

Components* OR::clone()
{
    return new OR;
}