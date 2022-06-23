#pragma once


#include <string>
#include <vector>

#include "LanguageLib.h"

using namespace std;

class ENLib : public LanguageLib
{
public:
    ENLib() {
        lib.push_back("Enter 'help' for all command options.");
        lib.push_back("help");
        lib.push_back("     Enter '1' to load in file\n     Enter '2' to change inputs\n     Enter '3' to print all data\n       Enter 'exit' to close program\n");
        lib.push_back("exit");
        lib.push_back("Enter path of file : ");
        lib.push_back("Enter component name : ");
        lib.push_back("Enter new value : ");
    };
    ENLib(vector<string> lib_) : lib(lib_) {};
       
    virtual ~ENLib() {}
    virtual string get_text(int i) override {
        return lib.at(i);
    }

    LanguageLib* Clone() const override   {
        return new ENLib(*this);
    }
private:
    vector<string> lib;
    
};
