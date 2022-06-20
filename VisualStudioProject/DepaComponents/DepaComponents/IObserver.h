#pragma once

class IObserver
{
public:
    virtual void Update(bool output, int index) = 0;  
};
