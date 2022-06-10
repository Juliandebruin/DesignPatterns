#include "NOR.h"

#include <iostream>

NOR NOR::m_cInstance(7);

NOR::NOR()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

NOR::NOR(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


Components* NOR::clone() const
{
    return new NOR;
}


NOR::~NOR()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void NOR::Update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - (_input[0] + _input[1]);
    PrintInfo();
    Sleep(propegation_delay_ms);
    Notify();
}

void NOR::PrintInfo()
{
    std::cout << "Observer NOR updated\n";
}
