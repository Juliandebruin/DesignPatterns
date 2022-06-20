#pragma once

#include <string>
#include "Components.h"

using namespace std;

class NOT : public Components
{
public:
    NOT();
    NOT(string componentName);
    virtual     ~NOT();

    void        Update(bool output, int index) override;
    void        PrintInfo()                    override;
    Components* clone()                        override;

private:
    static NOT _instance;
};
