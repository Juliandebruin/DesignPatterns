#include "LanguageLibrary.h"
#include "FactoryMethod.h"
#include "UserInterface.h"
#include "FileParser.h"
#include "Components.h"

#include <iostream>
#include <string>

using std::istringstream;
using namespace std;

UserInterface::UserInterface():
	_process()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::start_interface()
{
	
	LanguageLibrary* libary = nullptr;
	string language;
	while (libary == nullptr) {
		cout << "Welcome, Welkom " << endl;
		cout << "Enter your language (en), Voer je taal in (nl): ";
		cin >> language;
		libary = FactoryMethod<std::string, LanguageLibrary>::create(language);
	}

	cout << libary->get_text("explenation") << endl;
	cout << "# ";
	string input;

	while (0==0) {
		cin >> input;
		if (input == libary->get_text("help_word")) {
			cout << libary->get_text("help_text") << endl;
		}
		else if (input == libary->get_text("close")) {
			break;
		}
		else if (input == "1") {
			string input_path = "";
			cout << libary->get_text("path_text");
			cin >> input_path;
			_process.execute_process(input_path);
		}
		else if (input == "2") {
			string component = "";
			cout << libary->get_text("component_text");
			cin >> component;
			string value_port = "";
			cout << libary->get_text("new_value_text");
			cin >> value_port;
			if (value_port == "1") 
				_process.change_input(component, 1);
			else
				_process.change_input(component, 0);
		}
		else if (input == "3") {
			_process.print_all();
		}

		cout << "# ";
	}
}