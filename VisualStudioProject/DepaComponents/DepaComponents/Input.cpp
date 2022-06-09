#pragma once
#include "Input.h"


#include <iostream>

Input Input::m_cInstance(1);

Input::Input()
{
    //std::cout << "in default constructor Afgeleide" << std::endl;
}

Input::Input(int id) : Components(id)
{
    //std::cout << "in assignment constructor Afgeleide" << std::endl;
}


Components* Input::clone() const
{
    return new Input;
}

Input::~Input()
{
    //std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void Input::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input;
    PrintInfo();
    Notify();
}

void Input::PrintInfo()
{
}
