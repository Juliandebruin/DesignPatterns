#pragma once
#include <string>
#include <vector>
#include <list>

#include "Utils.h"
#include "Components.h"
#include "FileReader.h"

/**
 * @brief Class parse information string to list of components
 */
class FileParser
{
public:
	FileParser(std::string fileName);
	virtual ~FileParser();

	void parse_nodes_and_links();

	void create_nodes();
	void create_links();

	void set_nodes(std::string nodes);
	void set_links(std::string links);

	void set_links(std::string links, std::string nodeName);

	Components* get_component(std::string componentName);

	std::string remove_from_string(std::string, char removeChar);
	std::string tokens_to_string(int start, int end, std::vector<std::string> tokens);
	std::vector<std::string> tokenizer(std::string tokenizeString, char tokenizeCharacter);

	bool check_for_description_end(std::vector<std::string> tokens, int position);
	void display_nodes_and_links();
	void print_all();
	void set_inputs();
	void print_outputs();

private:
	Utils _utils;
	int _nodes_size; 
	Components** _components;
	FileReader  _file_reader; /*< File reader object */
	std::string _file_node_description; /*< Description of all nodes */
	std::string _file_link_description; /*< Description of all links */

	struct Input { string name; int value; } ;
	std::vector<Input>* input_values;
};

/**
	 * @brief Tokenize a string with a character
	 *
	 * @param tokenizeString String which will be tokenized
	 * @param tokenizeCharacter Character used to tokenize the tokenizeString
	 * @return std::vector<std::string> Returns a vector containing a list strings tokenized according to the tokenizeCharacter
	 */

