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
    _input2.at(index) = output;
    bool temp_state = 0;
    for (int i = 0; i < _input2.size(); i++) {
        temp_state = 1 * _input2.at(i);
    }
    _output = temp_state;

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