#include <iostream>
#include <list>
#include <string>
#include "Components.h"

using namespace std;


class OR : public Components
{
public:
    OR();
    OR(int);
    virtual ~OR();

    void Update(bool output, int index) override;
    void PrintInfo();
    Components* clone() const  override;

private:
    static OR m_cInstance;
};