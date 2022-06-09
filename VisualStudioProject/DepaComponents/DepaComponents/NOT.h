#pragma once

#include <iostream>
#include <list>
#include <string>


#include "Components.h"

using namespace std;

class NOT : public Components
{
public:
    NOT();
    NOT(int);
    virtual ~NOT();

    void Update(bool output, int index) override;
    void PrintInfo();
    Components* clone() const  override;

private:
    static NOT m_cInstance;
};

