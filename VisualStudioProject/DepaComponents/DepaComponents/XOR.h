#pragma once

#include <string>
#include "Components.h"

using namespace std;

class XOR : public Components
{
public:
    XOR();
    XOR(string componentName);
    virtual     ~XOR();

    void        update(bool output, int index) override;
    void        PrintInfo()                    override;
    Components* clone()                        override;

private:
    static XOR _instance;
};
