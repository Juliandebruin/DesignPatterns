#include "Input.h"
#include <iostream>

Input Input::_instance("INPUT");

Input::Input(Input* clonable)
{
}

Input::Input(string componentName) :
    Components(componentName)
{
}

Input::~Input()
{
}

void Input::Update(bool output, int index)
{
    _input[index] = output;
    _output = _input;
    Notify();
}

void Input::PrintInfo()
{
}

Components* Input::clone()
{
    return new Input(this);
}