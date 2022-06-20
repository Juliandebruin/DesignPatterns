#include "FactoryLangLib.h"
#include "UserInterface.h"
#include "FileParser.h"
#include "Components.h"

#include <iostream>
#include <string>

using namespace std;

UserInterface::UserInterface():
	_file_parser()
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
	cout << "# ";
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
			_file_parser.parse_file(input_path);
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
			_file_parser.print_all();
		}
		cout << "# ";
	}
}

void UserInterface::change_input(string name, bool value)
{
	Components* com = _file_parser.get_component(name);
	com->set_input(value);
	_file_parser.print_outputs();
}
