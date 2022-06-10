#pragma once

#include "FileParser.h"

class UserInterface
{
public:
	UserInterface();
	virtual ~UserInterface();

	void start_interface();
private:
	void load_file();
	void change_input(string name, bool value);
	FileParser* fParser = nullptr;
};

