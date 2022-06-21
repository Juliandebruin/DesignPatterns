#include "AND.h"
#include <iostream>

AND AND::_instance("AND");

AND::AND()
{
}

AND::AND(string componentName) :
    Components(componentName)
{
}

AND::~AND()
{
}

void AND::update(bool output, int index)
{
    _input[index] = output;
    _output = _input[0] * _input[1];
    Sleep(propegation_delay_ms);
    notify();
}

void AND::PrintInfo()
{
    std::cout << "Observer AND updated\n";
}

Components* AND::clone()
{
    return new AND;
}