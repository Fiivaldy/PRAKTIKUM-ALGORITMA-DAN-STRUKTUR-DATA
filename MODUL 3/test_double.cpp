#include "double_linked_list.h"
#include <iostream>

using namespace std;
int main() {

    DoubleLinkedList characterList;
    characterList.init();
    characterList.add_back('A');
    characterList.add_back('B');
    characterList.add_back('C');
    characterList.add_front('X');
    characterList.add_idx('Y', 2);
    cout << "Data awal : ";
    characterList.display();
    characterList.delete_front();
    cout << "Setelah delete front : ";
    characterList.display();
    characterList.delete_back();
    cout << "Setelah delete back : ";
    characterList.display();
    characterList.delete_idx(1);
    cout << "Setelah delete index 1 : ";
    characterList.display();
    cout << "Data index 0 : "
         << characterList.get(0)
         << endl;
    characterList.set('Z', 0);
    cout << "Setelah set data : ";
    characterList.display();
    characterList.clear();
    cout << "Setelah clear : ";
    characterList.display();

    return 0;
}