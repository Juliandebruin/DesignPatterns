#pragma once
#include "Components.h"

#include <string>
#include <vector>

class FileParser
{
public:
	FileParser();
	virtual ~FileParser();

	// ! Speciale pijl classen diagram voor FileReader
	void parse_file(std::string fileName);

	void split_file();
	void create_nodes();
	void create_links();

	void set_links(std::string links, std::string nodeName);
	std::string clear_string(std::string);
	
	Components* get_component(std::string componentName);
	
	std::string tokens_to_string(int start, int end, std::vector<std::string> tokens);
	std::vector<std::string> tokenizer(std::string tokenizeString, char tokenizeCharacter);

	bool check_for_description_end(std::vector<std::string> tokens, int position);
	void display_nodes_and_links();

	// TODO: Quinn dit moet ook weg
	void print_all();
	void set_inputs();
	void print_outputs();

private:
	std::string _file_string;			  /*!< File saved as string		*/
	std::vector<Components*> _components; /*!< List of components		*/
	std::string _file_node_description;   /*!< Description of all nodes */
	std::string _file_link_description;   /*!< Description of all links */

	// TODO: Quinn dit moet dus ook weg
	struct Input { string name; int value; };
	std::vector<Input>* input_values;
};

