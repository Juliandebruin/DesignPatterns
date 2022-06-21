#pragma once

#include "Subject.h"
#include "IObserver.h"
#include <thread>
#include <iostream>


void Subject::attach(IObserver* observer, int index)
{
    _ids.push_back(index);
    _list_observer.push_back(observer);
}

void Subject::detach(IObserver* observer)
{
    //_list_observer.remove(observer);
}

void Subject::notify()
{
    int i = 0;
    thread* t = nullptr;
    std::vector<thread*> vec;

    for (int i = 0; i < _list_observer.size(); i++)
    {
        id = _ids.at(i);
        index_update = i;
        t= new thread([this] {_list_observer.at(index_update)->update(_output, id); });
        vec.push_back(t);
    }
   
    for (int i = 0; i < _list_observer.size(); i++)
    {
        vec.at(i)->join();
    }
}

void Subject::create_massage(std::string message)
{
    this->_message = message;
    notify();
}

void Subject::how_many_observers()
{
    std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
}

void Subject::set_input(bool value)
{
    _output = value;
    notify();
}
