#pragma once

#include "FileParser.h"

class UserInterface
{
public:
	UserInterface();
	virtual ~UserInterface();

	void start_interface();
	void change_input(string name, bool value);

private:
	FileParser _file_parser;
};

