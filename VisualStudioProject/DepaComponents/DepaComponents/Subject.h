#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
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

    std::list<IObserver*> _list_observer;
private:
    std::string _message;

    std::vector<int> _ids;
    

protected:
    int _number_of_listeners;
    int id;
    std::list<IObserver*>::iterator iterator;

    bool _input[10] = { 0,0,0,0,0,0,0,0,0 };
};

