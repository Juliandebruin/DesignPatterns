#include "NAND.h"

#include <iostream>

NAND NAND::m_cInstance(6);

NAND::NAND()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

NAND::NAND(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


Components* NAND::clone() const
{
    return new NAND;
}


NAND::~NAND()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void NAND::Update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - _input[0] * _input[1];
    PrintInfo();
    Sleep(propegation_delay_ms);
    Notify();
}

void NAND::PrintInfo()
{
    std::cout << "Observer NAND updated\n";
}
