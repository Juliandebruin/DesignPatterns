#include "Output.h"
#include <iostream>

Output Output::_instance("PROBE");

Output::Output()
{
}

Output::Output(string componentName) :
    Components(componentName)
{
}

Output::~Output()
{
}

void Output::update(bool output, int index)
{
    _input[0] = output;
    _output = _input[0];
    notify();
}

void Output::PrintInfo()
{
    std::cout << "Observer" << "output " << _output << "\n";
}

Components* Output::clone()
{
    return new Output;
}