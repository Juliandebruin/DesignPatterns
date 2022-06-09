#include "XOR.h"
#include <iostream>

XOR XOR::m_cInstance(8);

XOR::XOR()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

XOR::XOR(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


Components* XOR::clone() const
{
    return new XOR;
}


XOR::~XOR()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void XOR::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input[0] * _input[1];
    PrintInfo();
    Notify();
}

void XOR::PrintInfo()
{
    std::cout << "Observer XOR updated\n";
}
