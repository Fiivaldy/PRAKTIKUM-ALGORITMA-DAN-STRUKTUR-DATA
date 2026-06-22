#include "single_linked_list.h"
#include <iostream>

using namespace std;

int main() {

    int totalStone;
    int initialJump;

    cin >> totalStone >> initialJump;
    SingleLinkedList relicCircle;
    relicCircle.init();
    for (int inputIndex = 0;
         inputIndex < totalStone;
         inputIndex++) {

        int stoneValue;

        cin >> stoneValue;

        relicCircle.add_back(stoneValue);
    }
    Node* currentStone = relicCircle.head;

    int currentJump = initialJump;
    while (relicCircle.size > 1) {
        if (currentJump <= 0) {
            currentJump = initialJump;
        }
        for (int stepCounter = 1;
             stepCounter < currentJump;
             stepCounter++) {

            currentStone = currentStone->next;
        }
        Node* destroyedStone = currentStone;

        int destroyedValue = destroyedStone->data;
        Node* previousStone = relicCircle.head;

        while (previousStone->next != destroyedStone) {

            previousStone = previousStone->next;
        }
        if (destroyedStone == relicCircle.head) {

            relicCircle.head = destroyedStone->next;

            relicCircle.tail->next = relicCircle.head;
        }
        if (destroyedStone == relicCircle.tail) {

            relicCircle.tail = previousStone;
        }
        previousStone->next = destroyedStone->next;
        currentStone = destroyedStone->next;
        delete destroyedStone;

        relicCircle.size--;
        if (destroyedValue % 2 == 0) {

            currentJump++;
        }
        else {

            currentJump--;
        }
    }
    cout << relicCircle.head->data << endl;
    return 0;
}