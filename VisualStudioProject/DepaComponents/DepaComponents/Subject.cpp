#pragma once

#include "Subject.h"
#include "IObserver.h"
#include <thread>
#include <iostream>


Subject::Subject()
{
}

Subject::~Subject()
{
}

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
        //_list_observer.at(index_update)->update(_output, id);
    }
   
    for (int i = 0; i < vec.size(); i++)
    {
        vec.at(i)->join();
        delete  vec.at(i);
    }

}

void Subject::set_input(bool value)
{
    _output = value;
    notify();
}

void Subject::create_ports(int size)
{
    for (int i = 0; i < size; i++)
    {
        _input2.push_back(0);
    }
}
