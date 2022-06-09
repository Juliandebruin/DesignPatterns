#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class IObserver;

class Subject 
{
public:
    Subject();
    virtual ~Subject();

    void Attach(IObserver* observer, int index);
    void Detach(IObserver* observer);
    void Notify();
    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();
    void set_input(bool value);
    
    /*void set_name(string name);
    string get_name();*/

private:
    //std::string _name;
    std::string _message;

    std::list<int> _ids;
    std::list<IObserver*> _list_observer;

public:
    int _number_of_listeners;
    bool _output = 0;
    bool _input[10];
};

