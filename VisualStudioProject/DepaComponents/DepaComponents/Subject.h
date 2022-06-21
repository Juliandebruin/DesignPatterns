#pragma once
#include <list>
#include <string>
#include <vector>

using namespace std;

class IObserver;

class Subject 
{
public:
    void attach(IObserver* observer, int index);
    void detach(IObserver* observer);
    void notify();
    void create_massage(std::string message = "Empty");
    void how_many_observers();
    void set_input(bool value);

    bool _output = 0;
    std::vector<IObserver*> _list_observer;

private:
    std::string _message;
    std::vector<int> _ids;    

protected:
    int id;
    int index_update;
    int _number_of_listeners;

    std::list<IObserver*>::iterator iterator;
    bool _input[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

};

