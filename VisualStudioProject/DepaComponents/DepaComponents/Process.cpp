#include "Process.h"

Process::Process() :
	_temp_inputs{},
	_components{}
{
}

Process::~Process()
{
}

void Process::execute_process(std::string filePath)
{
	_file_parser.parse_file(filePath);

	_temp_inputs = _file_parser.get_inputs();
	_components  = _file_parser.get_components();

	set_inputs();
	print_outputs();
}

Components* Process::get_component(std::string componentName)
{
	for (int i = 0; i < _components.size(); i++) {
		if (componentName == _components[i]->get_name()) {
			return _components[i];
		}
	}

	return nullptr;
}

void Process::set_inputs()
{
	for (int i = 0; i < _temp_inputs.size(); i++) {
		TempInput* input = _temp_inputs[i];
		Components* input_port = get_component(input->get_name());
		input_port->set_input(input->get_value());
	}
}

void Process::print_all()
{
	for (int i = 0; i < _components.size(); i++)
	{
		std::cout << "   Name: " << _components[i]->get_name() << " Output: " << _components[i]->_output << std::endl;
	}
}

void Process::print_outputs()
{
	for (int i = 0; i < _components.size(); i++)
	{
		if (_components[i]->get_type() == "PROBE")
			std::cout << "   Name: " << _components[i]->get_name() << " Output: " << _components[i]->_output << std::endl;
	}
}

void Process::change_input(std::string componentName, bool inputValue)
{
	Components* component = get_component(componentName);
	if (component != nullptr)
	{
		component->set_input(inputValue);
		print_outputs();
	}
}

