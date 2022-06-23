#include "Input.h"
#include <iostream>

Input Input::_instance("INPUT");

Input::Input()
{
}

Input::Input(string componentName) :
    Components(componentName)
{
}

Input::~Input()
{
}

void Input::update(bool output, int index)
{
    _input[index] = output;
    _output = _input;
    notify();
}

void Input::PrintInfo()
{
}

Components* Input::clone()
{
    return new Input;
}