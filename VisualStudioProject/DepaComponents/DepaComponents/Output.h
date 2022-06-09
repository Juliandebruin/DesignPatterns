#include <iostream>
#include <list>
#include <string>
#include "Components.h"

using namespace std;


class Output : public Components
{
public:
    Output();
    Output(int);
    virtual ~Output();

    void Update(bool output, int index) override;
    void PrintInfo();
    Components* clone() const  override;

private:
    static Output m_cInstance;
};