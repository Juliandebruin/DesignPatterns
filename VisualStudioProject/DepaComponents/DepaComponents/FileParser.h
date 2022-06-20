#pragma once
#include "Components.h"
#include "TempInput.h"

#include <string>
#include <vector>

class FileParser
{
public:
	FileParser();
	virtual ~FileParser();

	// ! Speciale pijl classen diagram voor FileReader
	void parse_file(std::string fileName);

	std::vector<TempInput*>	 get_inputs();
	std::vector<Components*> get_components();
	int get_index(vector<string> v, string K);

private:
	void split_file();
	void create_nodes();
	void create_links();

	Components* get_component(std::string componentName);
	
	std::string clear_string(std::string);
	std::string set_temp_inputs(std::string nodeName, std::string oldType);
	void set_links(std::string links, std::string nodeName);
	
	std::string tokens_to_string(int start, int end, std::vector<std::string> tokens);
	std::vector<std::string> tokenizer(std::string tokenizeString, char tokenizeCharacter);
	bool check_for_description_end(std::vector<std::string> tokens, int position);
	void display_nodes_and_links();


private:
	std::vector<TempInput*> _temp_inputs; /*!< List of temp_inputs		*/
	std::vector<Components*> _components; /*!< List of components		*/

	std::string _file_string;			  /*!< File saved as string		*/
	std::string _file_node_description;   /*!< Description of all nodes */
	std::string _file_link_description;   /*!< Description of all links */
};

