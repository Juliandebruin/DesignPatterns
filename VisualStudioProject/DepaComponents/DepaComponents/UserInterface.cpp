#include "UserInterface.h"

#include <iostream>
#include <string>
#include <list>

#include "FileParser.h"
#include "Components.h"
#include "FactoryMethod.h"
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface()
{
	

}

UserInterface::~UserInterface()
{
}

void UserInterface::start_interface()
{
	cout << "Welcome" << endl;
	cout << "Eneter 'help' for all command options." << endl;
	string input;
	while (cin >> input) {
		if (input == "help") {
			cout << "	Enter '1' to load in file" << endl;
			cout << "	Enter '2' to show all outputs" << endl;
			cout << "	Enter '3' to show all inputs" << endl;
			cout << "	Enter '4' to change inputs" << endl;
			cout << "	Enter 'exit' to close program" << endl;
		}
		else if (input == "exit") {
			break;

		}
		else if (input == "1") {
			load_file();

		}
		else if (input == "2") {
			string component = "hoi";
			cout << "Enter name component:";
			cin >> component;
			bool value;
			cout << "Enter value:";
			cin >> value;
			change_input(component, value);
		}

	}
	
}

void UserInterface::load_file()
{
	string input_path = "hoi";
	cout << "Enter path of file:" ;
	cin >> input_path;
	input_path = "PdfExample.txt";
	fParser= new FileParser(input_path);
	

	fParser->parse_nodes_and_links();
	//fParser.display_nodes_and_links();

	fParser->create_nodes();
	fParser->create_links();

	Components* A = fParser->get_component("A");
	Components* B = fParser->get_component("B");
	Components* Cin = fParser->get_component("C");

	A->set_input(0);
	B->set_input(1);
	Cin->set_input(1);


	fParser->print_all();
}

void UserInterface::change_input(string name, bool value)
{
	Components* com = fParser->get_component(name);
	com->set_input(value);
	fParser->print_all();
}
