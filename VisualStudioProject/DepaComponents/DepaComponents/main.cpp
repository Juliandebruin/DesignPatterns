
#include <iostream>
#include <string>
#include <list>

#include "FileParser.h"
#include "Components.h"
#include "FactoryMethod.h"

using namespace std;

void Circuit() {

    /*map<string, int> mymap;
    mymap["INPUT"] = 1;
    mymap["OUTPUT"] = 2;
    mymap["AND"] = 3;
    mymap["OR"] = 4;
    mymap["NOT"] = 5;
    mymap["NAND"] = 6;
    mymap["NOR"] = 7;
    mymap["XOR"] = 8;

    Components* input_1 = Factory::FactoryMethod<int, Components>::create(mymap["INPUT"]);

    Components* input_2 = Factory::FactoryMethod<int, Components>::create(mymap["INPUT"]);
    Components* input_3 = Factory::FactoryMethod<int, Components>::create(mymap["INPUT"]);

    Components* and_1 = Factory::FactoryMethod<int, Components>::create(mymap["AND"]);

    Components* and_2 = Factory::FactoryMethod<int, Components>::create(mymap["AND"]);
    Components* output = Factory::FactoryMethod<int, Components>::create(mymap["OUTPUT"]);

    input_1->set_list(*and_1);
    input_2->set_list(*and_1);

    and_1->set_list(*and_2);
    input_3->set_list(*and_2);

    and_2->set_list(*output);

    input_1->set_input(1);
    input_2->set_input(1);
    input_3->set_input(1);*/

}

int main() {
    FileParser fParser("PdfExample.txt");

    fParser.parse_nodes_and_links();
    fParser.display_nodes_and_links();

    fParser.create_nodes();
    fParser.create_links();

    Components *A = fParser.get_component("A");
    Components *B = fParser.get_component("B");
    Components *Cin = fParser.get_component("Cin");

    A->set_input(1);
    B->set_input(1);
    Cin->set_input(0);

    Circuit();

    return 0;
}