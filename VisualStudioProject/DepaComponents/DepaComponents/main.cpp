
#include <iostream>
#include <string>
#include <list>

#include "FileParser.h"
#include "Components.h"
#include "FactoryMethod.h"

using namespace std;

int main() {
    FileParser fParser("PdfExample.txt");

    fParser.parse_nodes_and_links();
    fParser.display_nodes_and_links();

    fParser.create_nodes();
    fParser.create_links();

    Components *A = fParser.get_component("A");
    Components *B = fParser.get_component("B");
    Components *Cin = fParser.get_component("Cin");

    A->set_input(0);
    B->set_input(1);
    Cin->set_input(0);

    fParser.print_all();

    return 0;
}