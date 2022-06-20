#pragma once

#include "Process.h"

class UserInterface
{
public:
	UserInterface();
	virtual ~UserInterface();

	void start_interface();

private:
	Process _process;
};

