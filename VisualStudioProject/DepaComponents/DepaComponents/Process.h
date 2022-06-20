#pragma once
#include "Components.h"
#include "FileParser.h"
#include "TempInput.h"

#include <string>
#include <vector>

class Process
{
public:
	Process();
	virtual ~Process();

	void execute_process(std::string filePath);

	Components* get_component(std::string componentName);

	void print_all();
	void set_inputs();
	void print_outputs();

	void change_input(std::string name, bool value);

private:
	FileParser _file_parser;

	std::vector<TempInput*> _temp_inputs; /*!< List of temp inputs */
	std::vector<Components*> _components; /*!< List of components  */
};

