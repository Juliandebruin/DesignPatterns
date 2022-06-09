#include "FactoryMethod.h"
#include "FileParser.h"
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

FileParser::FileParser(std::string fileName):
	_nodes_size(0),
	_file_reader(fileName),
	_file_node_description(""),
	_file_link_description("")
{
}

FileParser::~FileParser()
{
}

bool FileParser::check_for_description_end(std::vector<std::string> tokens, int position)
{
	if (tokens.size() > position + 1)
	{
		if ((tokens[position].find('#') == -1) && (tokens[position + 1].find('#') != -1))
		{
			return true;
		}
	}
		
	return false;
}

void FileParser::parse_nodes_and_links()
{
	bool nodesDesc = false;
	bool delayCheck = false;

	std::vector<std::string> tokens = tokenizer(_file_reader.get_file_content(), '\n');

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
	std::cout << "\nNodes: \n" << std::endl;
	std::vector<std::string> nodes = tokenizer(_file_node_description, ';');

	_nodes_size = nodes.size();
	_components = new Components * [_nodes_size];

	for (int i = 0; i < nodes.size(); i++)
	{
		std::vector<std::string> node = tokenizer(nodes[i], ':');

		if (node.size() == 2)
		{
			std::string nodeName = node[0];
			std::string nodeType = node[1];

			nodeName = remove_from_string(nodeName, ' ' );
			nodeName = remove_from_string(nodeName, '\n');
			nodeType = remove_from_string(nodeType, ' ' );
			nodeType = remove_from_string(nodeType, '\n');

			int componentId = _utils.get_component_id(nodeType);

			if (componentId != -1) {
				Components* component = Factory::FactoryMethod<int, Components>::create(componentId);
				component->set_name(nodeName);
				_components[i] = component;
			}
			else {
				std::cout << "Componenttype not found" << std::endl;
			}			

			std::cout << "Nodename: " << nodeName << " Nodetype: " << nodeType << std::endl;
		}
	}
}

Components* FileParser::get_component(std::string componentName)
{
	for (int i = 0; i < _nodes_size; i++) {
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
		else {
			std::cout << "Component name can not be found in _components" << std::endl;
		}
	}
}

void FileParser::create_links()
{
	std::cout << "\nLinks: \n" << std::endl;
	std::vector<std::string> links = tokenizer(_file_link_description, ';');

	for (int i = 0; i < links.size(); i++)
	{
		std::vector<std::string> link = tokenizer(links[i], ':');

		if (link.size() == 2)
		{
			std::string nodeName = link[0];
			std::string links    = link[1];

			nodeName = remove_from_string(nodeName, ' ' );
			nodeName = remove_from_string(nodeName, '\n');
			links = remove_from_string(links, ' ' );
			links = remove_from_string(links, '\n');

			set_links(links, nodeName);
		}
	}
}

void FileParser::set_nodes(std::string nodes)
{
	_file_node_description = nodes;
}

void FileParser::set_links(std::string links)
{
	_file_link_description = links;
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

std::string FileParser::remove_from_string(std::string str, char removeChar)
{
	str.erase(remove(str.begin(), str.end(), removeChar), str.end());

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