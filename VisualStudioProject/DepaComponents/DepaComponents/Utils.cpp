#include "Utils.h"

Utils::Utils() :
    _component_map{
        {"INPUT" , 1},
        {"PROBE" , 2},
        {"AND"   , 3},
        {"OR"    , 4},
        {"NOT"   , 5},
        {"NAND"  , 6},
        {"NOR"   , 7},
        {"XOR"   , 8}
    }
{
}

Utils::~Utils()
{
}

int Utils::get_component_id(string componentName)
{
    if (componentName == "INPUT_HIGH" || componentName == "INPUT_LOW") {
        componentName = "INPUT";
    }

    int id = _component_map[componentName];

    if (id >= 1 && id <= 8) {
        return id;
    }
    else {
        return -1;
    }
}
