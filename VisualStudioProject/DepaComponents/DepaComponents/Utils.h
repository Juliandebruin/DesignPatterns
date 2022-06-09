#pragma once
#include <map>
#include <string>

using namespace std;

class Utils
{
public:
	Utils();
	virtual ~Utils();

	int get_component_id(string componentName);

private:
	map<string, int> _component_map;
};

