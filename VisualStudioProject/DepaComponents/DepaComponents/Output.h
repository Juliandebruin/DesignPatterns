#pragma once

#include <string>
#include "Components.h"

using namespace std;

class Output : public Components
{
public:
    Output(Output* clonable);
    Output(string componentName);
    virtual     ~Output();

    void        Update(bool output, int index) override;
    void        PrintInfo()                    override;
    Components* clone()                        override;

private:
    static Output _instance;
};
