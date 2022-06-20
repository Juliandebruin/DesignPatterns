#include "EnglishLibrary.h"

EnglishLibrary EnglishLibrary::_instance("en");

EnglishLibrary::EnglishLibrary() :
    _help_text_libary{
        {"explenation"   , "Enter 'help' for all command options."},
        {"help_word"     , "help"},
        {"help_text"     , "     Enter '1' to load in file\n     Enter '2' to change inputs\n     Enter '3' to print all data\n     Enter 'exit' to close program\n"},
        {"close"         , "exit"},
        {"path_text"     , "Enter path of file : "},
        {"component_text", "Enter component name : "},
        {"new_value_text", "Enter new value : "}
}
{
}

EnglishLibrary::EnglishLibrary(std::string libaryName) :
    _help_text_libary{},
    LanguageLibrary(libaryName)
{
}

EnglishLibrary::~EnglishLibrary()
{
}

std::string EnglishLibrary::get_text(std::string key)
{
    return _help_text_libary[key];
}

EnglishLibrary* EnglishLibrary::clone()
{
    return new EnglishLibrary;
}

