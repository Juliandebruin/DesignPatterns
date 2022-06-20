#include "TempInput.h"

TempInput::TempInput(std::string name, int value) :
	_name(name),
	_value(value)
{
}

TempInput::~TempInput()
{
}

std::string TempInput::get_name()
{
	return _name;
}

int TempInput::get_value()
{
	return _value;
}
