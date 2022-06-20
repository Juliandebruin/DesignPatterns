#pragma once

#include <string>
#include "Components.h"

using namespace std;

class Input : public Components
{
public:
    Input();
    Input(string componentName);
    virtual     ~Input();

    void        Update(bool output, int index) override;
    void        PrintInfo()                    override;
    Components* clone()                        override;

private:
    static Input _instance;
};
