#pragma once
#include "Input.h"


#include <iostream>

Input Input::m_cInstance(1);

Input::Input()
{
}

Input::Input(int id) : Components(id){
}


Components* Input::clone() const
{
    return new Input;
}

Input::~Input()
{
}

void Input::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input;
    //PrintInfo();
    Notify();
}

void Input::PrintInfo()
{
}
