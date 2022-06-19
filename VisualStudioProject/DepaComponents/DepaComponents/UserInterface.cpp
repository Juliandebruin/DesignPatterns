#include "UserInterface.h"

#include <iostream>
#include <string>
#include <list>

#include "FileParser.h"
#include "Components.h"
#include "FactoryMethod.h"
#include "UserInterface.h"

#include "FactoryLangLib.h"

using namespace std;

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::start_interface()
{
	cout << "Welcome, Welkom " << endl;
	cout << "Enter your language (en), Voer je taal in(nl): ";
	string language;
	cin >> language;

	FactoryLangLib* factorylib = new FactoryLangLib();
	LanguageLib* text = factorylib->CreatePrototype(language);

	cout << text->get_text(0) << endl;
	cout << "#";
	string input;
	while (cin >> input) {
		if (input == text->get_text(1)) {
			cout << text->get_text(2) << endl;
		}
		else if (input == text->get_text(3)) {
			break;
		}
		else if (input == "1") {
			string input_path = "";
			cout << text->get_text(4);
			cin >> input_path;
			input_path = "PdfExample.txt";
			load_file(input_path);
		}
		else if (input == "2") {
			string component = "";
			cout << text->get_text(5);
			cin >> component;
			bool value;
			cout << text->get_text(6);
			cin >> value;
			change_input(component, value);
		}
		else if (input == "3") {
			fParser->print_all();
		}
		cout << "#";
	}
	
}

void UserInterface::load_file(string input_path)
{
	
	fParser= new FileParser(input_path);
	

	fParser->parse_nodes_and_links();
	fParser->create_nodes();
	fParser->create_links();

	fParser->set_inputs();
	fParser->print_outputs();

}

void UserInterface::change_input(string name, bool value)
{
	Components* com = fParser->get_component(name);
	com->set_input(value);
	fParser->print_outputs();
}
