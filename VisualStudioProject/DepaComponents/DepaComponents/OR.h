#pragma once

#include <string>
#include "Components.h"

using namespace std;

/**
 * @brief Class to calculate values of a or port
 */
class OR : public Components
{
public:
    OR();
    OR(string componentName);
    virtual ~OR();

    /**
    * @brief calculate new output and update other components
    *
    * @param output value of connected component
    * @param index input port number
    */
    void update(bool output, int index) override;
    /**
    * @brief show info of component
    */
    void PrintInfo() override;
    /**
    * @brief get copy of component
    */
    Components* clone() override;

private:
    static OR _instance;/*< instance of or */
};