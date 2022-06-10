#include "NOT.h"

#include <iostream>

NOT NOT::m_cInstance(5);

NOT::NOT()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

NOT::NOT(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


Components* NOT::clone() const
{
    return new NOT;
}


NOT::~NOT()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void NOT::Update(bool output, int index)
{
    _input[index] = output;
    _output = 1 - _input[0];
    PrintInfo();
    Notify();
}

void NOT::PrintInfo()
{
    std::cout << "Observer AND updated\n";
}
