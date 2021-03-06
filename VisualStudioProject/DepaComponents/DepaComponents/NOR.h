#pragma once

#include <string>
#include "Components.h"

using namespace std;

class NOR : public Components
{
public:
    NOR();
    NOR(string componentName);
    virtual     ~NOR();

    void        update(bool output, int index) override;
    void        PrintInfo()                    override;
    Components* clone()                        override;

private:
    static NOR _instance;
};

