#pragma once
#include <list>
#include <string>
#include <vector>

using namespace std;

class IObserver;

class Subject 
{
public:
    Subject();
    virtual ~Subject();
    void attach(IObserver* observer, int index);
    void detach(IObserver* observer);
    void notify();
 
    void set_input(bool value);
    void create_ports(int);

    bool _output = 0;
    std::vector<IObserver*> _list_observer;

private:
    std::vector<int> _ids;    

protected:
    int id;
    int index_update;
    int _number_of_listeners;

    std::list<IObserver*>::iterator iterator;
    bool _input[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<bool> _input2;
};

