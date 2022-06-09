

#include <iostream>
#include <list>
#include <string>
#include "Components.h"

using namespace std;

class Input : public Components
{

public:
    Input();
    Input(int);
    virtual ~Input();

    void Update(bool output, int index) override;
    void PrintInfo();
    Components* clone() const  override;

private:
    static Input m_cInstance;

private:

};

