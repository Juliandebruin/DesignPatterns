#include "XOR.h"
#include <iostream>

XOR XOR::_instance("XOR");

XOR::XOR(XOR* clonable)
{
}

XOR::XOR(string componentName) :
    Components(componentName)
{
}

XOR::~XOR()
{
}

void XOR::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input[0] * _input[1];
    Sleep(propegation_delay_ms);
    Notify();
}

void XOR::PrintInfo()
{
    std::cout << "Observer XOR updated\n";
}

Components* XOR::clone()
{
    return new XOR(this);
}
