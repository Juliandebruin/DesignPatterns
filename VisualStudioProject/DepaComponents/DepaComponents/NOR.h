#pragma once

#include <iostream>
#include <list>
#include <string>


#include "Components.h"

using namespace std;

class NOR : public Components
{
public:
    NOR();
    NOR(int);
    virtual ~NOR();

    void Update(bool output, int index) override;
    void PrintInfo();
    Components* clone() const  override;

private:
    static NOR m_cInstance;
};

