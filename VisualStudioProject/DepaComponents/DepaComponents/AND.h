#pragma once

#include <iostream>
#include <list>
#include <string>
#include "Components.h"

using namespace std;

class AND : public Components
{
public:
    AND();
    AND(int);
    virtual ~AND();
 
    void Update(bool output, int index) override;
    void PrintInfo();
   
    Components* clone() const  override;
private:
    static AND m_cInstance;
};