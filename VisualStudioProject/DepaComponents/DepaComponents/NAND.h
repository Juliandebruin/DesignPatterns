#pragma once

#include <iostream>
#include <list>
#include <string>


#include "Components.h"

using namespace std;

class NAND : public Components
{
public:
    NAND();
    NAND(int);
    virtual ~NAND();

    void Update(bool output, int index) override;
    void PrintInfo();

    Components* clone() const  override;

private:
    static NAND m_cInstance;
};

