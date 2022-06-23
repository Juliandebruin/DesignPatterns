#pragma once

class IObserver
{
public:
    virtual void update(bool output, int index) = 0;  
};
