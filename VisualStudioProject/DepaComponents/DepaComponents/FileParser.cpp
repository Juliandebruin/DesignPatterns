#include "FactoryMethod.h"
#include "FileReader.h"
#include "FileParser.h"
#include <iostream>
#include <sstream>
#include <list>

FileParser::FileParser():
	_components{},
	_file_string(""),
	_file_node_description(""),
	_file_link_description("")
{
}

FileParser::~FileParser()
{
}

void FileParser::parse_file(std::string fileName)
{
	FileReader fileReader(fileName);
	_file_string = fileReader.get_file_content();

	split_file();
	create_nodes();
	create_links();

	// TODO: Quinn moet ergens anders
	set_inputs();
	print_outputs();
}

void FileParser::split_file()
{
	bool nodesDesc = false;
	bool delayCheck = false;

	std::vector<std::string> tokens = tokenizer(_file_string, '\n');

	for (int i = 0; i < tokens.size(); i++)
	{
		if (delayCheck)
		{
			if (!nodesDesc)
			{
				nodesDesc = true;
			}
		}

		if ((tokens[i].find('#') == -1))
		{
			std::string parseString = tokens[i];
			int tokenPos = parseString.find(';');

			if (tokenPos != -1)
			{
				parseString = parseString.substr(0, tokenPos + 1) + '\n' + parseString.substr(tokenPos + 1, parseString.length());
			}

			if (!nodesDesc)
			{
				_file_node_description += parseString;
			}
			else
			{
				_file_link_description += parseString;
			}
		}

		delayCheck = check_for_description_end(tokens, i);
	}
}

void FileParser::create_nodes()
{
	std::vector<std::string> nodes = tokenizer(_file_node_description, ';');

	input_values = new vector<Input>();
	for (int i = 0; i < nodes.size(); i++)
	{
		std::vector<std::string> node = tokenizer(nodes[i], ':');

		if (node.size() == 2)
		{
			std::string nodeName = node[0];
			std::string nodeType = node[1];

			nodeName = clear_string(nodeName);
			nodeType = clear_string(nodeType);

			// TODO: Quinn dit moet weg
			if (nodeType == "INPUT_HIGH") {
				nodeType = "INPUT";
				Input input;
				input.name = nodeName;
				input.value = 1;
				input_values->push_back(input);

			} else if ( nodeType == "INPUT_LOW") {
				nodeType = "INPUT";
				Input input;
				input.name = nodeName;
				input.value = 0;
				input_values->push_back(input);
			}

			Components* component = FactoryMethod<std::string, Components>::create(nodeType);
			
			if (component != nullptr) {
				component->set_name(nodeName);
				component->set_type(nodeType);
				_components.push_back(component);
			}
		}
	}
}

Components* FileParser::get_component(std::string componentName)
{
	for (int i = 0; i < _components.size(); i++) {
		if (componentName == _components[i]->get_name()) {
			return _components[i];
		}
	}

	return nullptr;
}

void FileParser::set_links(std::string links, std::string nodeName)
{
	std::vector<std::string> linkName = tokenizer(links, ',');

	for (int i = 0; i < linkName.size(); i++)
	{
		Components* component = get_component(nodeName);
		Components* link	  = get_component(linkName[i]);

		if (component != nullptr && link != nullptr) {
			component->set_list(*link);
		}
		else if (link == nullptr) {
			std::cout << "Component name can not be found in _components" << std::endl;
		}
	}
}

void FileParser::create_links()
{
	std::vector<std::string> links = tokenizer(_file_link_description, ';');

	for (int i = 0; i < links.size(); i++)
	{
		std::vector<std::string> link = tokenizer(links[i], ':');

		if (link.size() == 2)
		{
			std::string nodeName = link[0];
			std::string links    = link[1];

			nodeName = clear_string(nodeName);
			links	 = clear_string(links	);

			set_links(links, nodeName);
		}
	}
}

bool FileParser::check_for_description_end(std::vector<std::string> tokens, int position)
{
	if (tokens.size() > position + 1) {
		if ((tokens[position].find('#') == -1) && (tokens[position + 1].find('#') != -1)) {
			return true;
		}
	}

	return false;
}

void FileParser::display_nodes_and_links()
{
	if ((_file_node_description != "") && (_file_link_description != ""))
	{
		std::cout << "Nodes:\n\n" + _file_node_description + "\n" << std::endl;
		std::cout << "Links:\n\n" + _file_link_description + "\n" << std::endl;
	}
	else
	{
		std::cout << "File has not been parsed yet." << std::endl;
	}
}

void FileParser::print_outputs()
{
	for (int i = 0; i < _components.size(); i++)
	{
		if (_components[i]->get_type() == "PROBE")
			std::cout << "   Name: " << _components[i]->get_name() << " Output: " << _components[i]->_output << std::endl;
	}
}

void FileParser::print_all()
{
	for (int i = 0; i < _components.size(); i++)
	{
		std::cout << "   Name: " << _components[i]->get_name() << " Output: " << _components[i]->_output << std::endl;
	}
}

void FileParser::set_inputs()
{
	for (int i = 0; i < input_values->size(); i++) {
		Input input= input_values->at(i);
		Components* input_port = get_component(input.name);
		input_port->set_input(input.value);
	}
}

std::string FileParser::clear_string(std::string str)
{
	str.erase(remove(str.begin(), str.end(), ' ' ), str.end());
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
	str.erase(remove(str.begin(), str.end(), '\t'), str.end());

	return str;
}

std::string FileParser::tokens_to_string(int start, int end, std::vector<std::string> tokens)
{
	std::string outputString = "";

	for (int i = start; i < end; i++)
	{
		outputString += tokens[i] + '\n';
	}

	return outputString;
}

std::vector<std::string> FileParser::tokenizer(std::string tokenizeString, char tokenizeCharacter)
{
	std::vector<std::string> tokens;

	std::string storedText;
	std::stringstream ss(tokenizeString);

	while (getline(ss, storedText, tokenizeCharacter))
	{
		tokens.push_back(storedText);
	}

	return tokens;
}