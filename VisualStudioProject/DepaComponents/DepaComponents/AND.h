#pragma once

#include <string>
#include "Components.h"

using namespace std;

/**
 * @brief Class to calculate values of a and port
 */
class AND : public Components
{
public:
    AND();
    AND(string componentName);
    virtual ~AND();

    /**
    * @brief calculate new output and update other components
    * 
    * @param output value of connected component
    * @param index input port number
    */
    void Update(bool output, int index) override;
    /**
    * @brief show info of component
    */
    void PrintInfo() override;
    /**
    * @brief get copy of component
    */
    Components* clone() override;

private:
    static AND _instance; /*< instance of and */
};