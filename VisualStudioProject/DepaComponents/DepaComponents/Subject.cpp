#pragma once

#include "Subject.h"
#include "IObserver.h"
#include <thread>
#include <iostream>


void Subject::Attach(IObserver* observer, int index)
{
    _ids.push_back(index);
    _list_observer.push_back(observer);
}

void Subject::Detach(IObserver* observer)
{
    _list_observer.remove(observer);
}

void Subject::Notify()
{
    int i = 0;
    thread* t = nullptr;
    std::vector<thread*> vec;
    iterator = _list_observer.begin();

    while (iterator != _list_observer.end()) {
        id = _ids.at(i);
        t= new thread([this] {(*iterator)->Update(_output, id); });
        t->join();
        vec.push_back(t);
        //(*iterator)->Update(_output, *it1);
        ++iterator;
        i++;
    }
   
}

void Subject::CreateMessage(std::string message)
{
    this->_message = message;
    Notify();
}

void Subject::HowManyObserver()
{
    std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
}

void Subject::set_input(bool value)
{
    _output = value;
    Notify();
}
