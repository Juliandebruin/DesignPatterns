#pragma once
#include <string>

class LanguageLibrary
{
protected:
	LanguageLibrary();
	LanguageLibrary(std::string libaryName);
	virtual ~LanguageLibrary();

public:
	virtual std::string	get_text(std::string key) = 0;
	virtual LanguageLibrary* clone()			  = 0;
};
