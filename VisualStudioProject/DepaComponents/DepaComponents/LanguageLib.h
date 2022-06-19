#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class LanguageLib
{
public:

	
	LanguageLib() {
		//libs["en"] = new ENLib();
		//libs[Language::NL] = new NLLib();
	}
	LanguageLib(vector<string> _lib): lib(_lib) {
	}
	virtual string get_text(int i) = 0;
	virtual LanguageLib* Clone() const = 0;

	vector<string> lib;

};

