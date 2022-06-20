#pragma once
#include "LanguageLibrary.h"
#include <map>

class DutchLibrary : public LanguageLibrary
{
public:
	DutchLibrary();
	DutchLibrary(std::string libaryName);
	virtual ~DutchLibrary();

	std::string	get_text(std::string key) override;
	LanguageLibrary* clone()				  override;

private:
	static DutchLibrary _instance;
	std::map<std::string, std::string> _help_text_libary;
};

