#include "DutchLibrary.h"

DutchLibrary DutchLibrary::_instance("nl");

DutchLibrary::DutchLibrary():
    _help_text_libary{
        {"explenation"   , "Voer in 'help' om alle commandos te weergeven."},
        {"help_word"     , "help"},
        {"help_text"     , "     Voer in '1'om een bestand in te laden\n     Voer in '2' om inputs te veranderen\n     Voer in '3' om alle data te printen\n     Voer in 'sluiten' om het programma te stoppen\n"},
        {"close"         , "sluiten"},
        {"path_text"     , "Voer path in van het bestand : "},
        {"component_text", "Voer in de naam van het component : "},
        {"new_value_text", "Voer de nieuwe waarde in : "}
    }
{
}

DutchLibrary::DutchLibrary(std::string libaryName):
    _help_text_libary{},
    LanguageLibrary(libaryName)
{
}

DutchLibrary::~DutchLibrary()
{
}

std::string DutchLibrary::get_text(std::string key)
{
    return _help_text_libary[key];
}

LanguageLibrary* DutchLibrary::clone()
{
    return new DutchLibrary;
}
