#pragma once
#include "LanguageLibrary.h"
#include <map>

class EnglishLibrary : public LanguageLibrary
{
public:
	EnglishLibrary();
	EnglishLibrary(std::string libaryName);
	virtual ~EnglishLibrary();

	std::string	get_text(std::string key) override;
	EnglishLibrary* clone()				  override;

private:
	static EnglishLibrary _instance;
	std::map<std::string, std::string> _help_text_libary;
};

