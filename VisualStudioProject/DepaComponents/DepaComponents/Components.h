#pragma once
#include "IObserver.h"
#include "Subject.h"
#include <functional>
#include <iostream>
#include <string>
#include <list>
#include<windows.h>


using namespace std;

class Components : public IObserver, public Subject
{
protected:
    Components();
    Components(int id);

public:
    virtual        ~Components();

    virtual void PrintInfo() = 0;
    virtual Components* clone() const = 0;
    virtual void set_list(Components& subject);
    void RemoveMeFromTheList();

    void set_name(string name);
    string get_name();
    
public:
    Subject& subject_ = *this;
    list<bool> inputs;
    bool output = 0;
    string _name;

    int propegation_delay_ms = 1;
};