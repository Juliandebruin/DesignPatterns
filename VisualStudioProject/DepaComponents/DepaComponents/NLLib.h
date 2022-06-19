#pragma once
#include "LanguageLib.h"
class NLLib :
    public LanguageLib
{

public:
    NLLib() {
        lib.push_back("Voer in 'help' om alle commandos te weergeven.");
        lib.push_back("help");
        lib.push_back("     Voer in '1'om een bestand in te laden\n     Voer in '2' om inputs te veranderen\n     Voer in '3' om alle data te printen\n     Voer in 'sluiten' om het programma te stoppen\n");
        lib.push_back("sluiten");
        lib.push_back("Voer path in van het bestand : ");
        lib.push_back("Voer in de naam van het component : ");
        lib.push_back("Voer de nieuwe waarde in : ");
    };
    NLLib(vector<string> lib_) : lib(lib_) {};

    virtual ~NLLib() {}
    virtual string get_text(int i) override {
        return lib.at(i);
    }

    LanguageLib* Clone() const override {
        return new NLLib(*this);
    }
private:
    vector<string> lib;

   
};

