#pragma once

#include <iostream>
#include <list>
#include <string>


#include "Components.h"

using namespace std;

class XOR : public Components
{public:
    XOR();
    XOR(int);
    virtual ~XOR();
 
    void Update(bool output, int index) override;
    void PrintInfo();
    Components* clone() const  override;

private:
    static XOR m_cInstance;
};

