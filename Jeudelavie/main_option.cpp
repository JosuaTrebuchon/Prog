#include "tabOption.h"
#include <iostream>

int main (int argc, char** argv){
    Option o(1, "test", "t", "option test", Option::ENTIER);
    Option o2, o3(2,"test2", "t2", "option test2");
    o.print();
    o2.print();
    o3.print();

    TabOption t;
    t.addOption(o);
    t.print();
    return 0;
}