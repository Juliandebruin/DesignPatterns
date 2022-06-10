#pragma once

#include "Subject.h"
#include "IObserver.h"



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
    std::list<IObserver*>::iterator iterator = _list_observer.begin();
    //HowManyObserver();
    int i = 0;
    while (iterator != _list_observer.end()) {
        auto it1 = std::next(_ids.begin(), i);
        (*iterator)->Update(_output, *it1);
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
