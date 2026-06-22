#include "single_linked_list.h"
#include <iostream>

using namespace std;

int main() {

    SingleLinkedList numberList;
    numberList.init();
    numberList.add_back(10);
    numberList.add_back(20);
    numberList.add_front(5);
    numberList.display();

    return 0;
}