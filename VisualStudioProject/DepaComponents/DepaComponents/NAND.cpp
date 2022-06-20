#include "NAND.h"
#include <iostream>

NAND NAND::_instance("NAND");

NAND::NAND()
{
}

NAND::NAND(string componentName) :
    Components(componentName)
{
}

NAND::~NAND()
{
}

void NAND::Update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - _input[0] * _input[1];
    Sleep(propegation_delay_ms);
    Notify();
}

void NAND::PrintInfo()
{
    std::cout << "Observer NAND updated\n";
}

Components* NAND::clone()
{
    return new NAND;
}