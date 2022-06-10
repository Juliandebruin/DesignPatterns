#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class IObserver;

class Subject 
{
public:

    void Attach(IObserver* observer, int index);
    void Detach(IObserver* observer);
    void Notify();
    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();
    void set_input(bool value);
    bool _output = 0;
private:
    std::string _message;

    std::list<int> _ids;
    std::list<IObserver*> _list_observer;

protected:
    int _number_of_listeners;
   
    bool _input[10] = { 0,0,0,0,0,0,0,0,0 };
};

