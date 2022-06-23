#include "LanguageLibrary.h"
#include "FactoryMethod.h"

LanguageLibrary::LanguageLibrary()
{
}

LanguageLibrary::LanguageLibrary(std::string libaryName)
{
	FactoryMethod<std::string, LanguageLibrary>::assign(libaryName, this);
}

LanguageLibrary::~LanguageLibrary()
{
}

