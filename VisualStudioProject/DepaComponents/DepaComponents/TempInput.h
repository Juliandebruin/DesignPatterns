#pragma once
#include <string>

class TempInput
{
public:
	TempInput(std::string name, int value);
	virtual ~TempInput();

	std::string get_name();
	int			get_value();

private:
	std::string _name;
	int			_value;
};

