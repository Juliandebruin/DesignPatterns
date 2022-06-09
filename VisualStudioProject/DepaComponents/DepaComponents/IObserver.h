#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;


class IObserver  {
public:
    virtual ~IObserver() {};
    virtual void Update(bool output, int index) = 0;  
};
