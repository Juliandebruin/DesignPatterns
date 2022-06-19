#include <iostream>
#include <list>
#include <string>
#include "Components.h"

using namespace std;

/**
 * @brief Class to calculate values of a or port
 */
class OR : public Components
{
public:
    /**
     * @brief Construct a new or object
     */
    OR();
    /**
     * @brief Construct a new and object
     *
     * @param id id of component
     */
    OR(int);
    /**
    * @brief Destroy the and object
    */
    virtual ~OR();
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
    void PrintInfo();
    /**
    * @brief get copy of component
    */
    Components* clone() const  override;

private:
    static OR m_cInstance;/*< instance of or */
};