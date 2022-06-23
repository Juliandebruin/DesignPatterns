#include "FactoryMethod.h"
#include "FileReader.h"
#include "FileParser.h"
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>

FileParser::FileParser():
	_components{},
	_temp_inputs{},
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
}

std::vector<TempInput*> FileParser::get_inputs()
{
	return _temp_inputs;
}

std::vector<Components*> FileParser::get_components()
{
	return _components;
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

std::string FileParser::set_temp_inputs(std::string nodeName, std::string nodeType)
{
	int inputValue;
	
	if (nodeType == "INPUT_HIGH") {
		inputValue = 1;
	}
	else if (nodeType == "INPUT_LOW") {
		inputValue = 0;
	}
	else {
		return nodeType;
	}

	TempInput* input = new TempInput(nodeName, inputValue);
	_temp_inputs.push_back(input);

	return "INPUT";
}

void FileParser::create_nodes()
{
	std::vector<std::string> nodes = tokenizer(_file_node_description, ';');

	for (int i = 0; i < nodes.size(); i++)
	{
		std::vector<std::string> node = tokenizer(nodes[i], ':');
		
		if (node.size() == 2)
		{
			std::string nodeName = node[0];
			std::string nodeType = node[1];

			nodeName = clear_string(nodeName);
			nodeType = clear_string(nodeType);
			nodeType = set_temp_inputs(nodeName, nodeType);

			
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
	Components* component = get_component(nodeName);
	component->create_ports(linkName.size());
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

int FileParser::get_index(vector<string> v, string K)
{
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == K)
			
			return i;
	}
	return -1;
}
/*
int FileParser::get_index(vector<std::string> v, string K)
{
	std::vector<string>::iterator it;
	it = std::find(v.begin(), v.end(), K);
	if (it != v.end())
	{
		return it - v.begin();
	}
	return -1;
}*/

void FileParser::create_links()
{
	std::vector<std::string> links = tokenizer(_file_link_description, ';');
	
	
	std::vector<std::string> links_parsed_first;
	std::vector<std::string> links_parsed_second;
	std::vector<std::string> used_output_ports;
	for (int i = 0; i < links.size(); i++)
	{
		std::vector<std::string> link = tokenizer(links[i], ':');
		if (link.size() == 2)
		{
			std::vector<std::string> linkName = tokenizer(link[1], ',');
			for (int j = 0; j < linkName.size(); j++) {
				links_parsed_first.push_back(clear_string(link[0]));
				links_parsed_second.push_back(clear_string(linkName[j]));
			}
		}
	}
	
	// recursie detection
	for (int i = 0; i < links_parsed_first.size(); i++)
	{
		used_output_ports.clear();
		std::string nodeName = links_parsed_first[i];
		std::string links = links_parsed_second[i];

		int index = get_index(links_parsed_first, links);
		while (index != -1) {
			std::string nodeName = links_parsed_first[index];
			std::string links = links_parsed_second[index];

			if (get_index(used_output_ports, links) == -1) {
				used_output_ports.push_back(links_parsed_second[index]);
			}
			else {
				cout << "recursie found";
				return;
			}
			index = get_index(links_parsed_first, links);
		}
		if (links_parsed_first.size() > 100) {
			i = links_parsed_first.size();
		}
	}
	

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