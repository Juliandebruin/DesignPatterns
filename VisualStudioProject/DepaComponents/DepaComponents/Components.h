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
    Components(string componentName);

public:
    virtual ~Components();

    virtual void        PrintInfo() = 0;
    virtual Components* clone()     = 0;

    virtual void set_list(Components& subject);
    void remove_from_list();

    void   set_name(string name);
    string get_name();
    string get_type();
    void   set_type(string);
    
public:
    Subject& subject_;
    string _name;
    string _type;

    int propegation_delay_ms;
};