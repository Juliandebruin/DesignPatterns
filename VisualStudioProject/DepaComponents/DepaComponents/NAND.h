#pragma once

#include <string>
#include "Components.h"

using namespace std;

class NAND : public Components
{
public:
    NAND();
    NAND(string componentName);
    virtual     ~NAND();

    void        Update(bool output, int index) override;
    void        PrintInfo()                    override;
    Components* clone()                        override;

private:
    static NAND _instance;
};
