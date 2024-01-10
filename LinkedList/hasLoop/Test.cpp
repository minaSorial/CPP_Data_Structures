#include <iostream> 
#include "LinkedList.h"

using namespace std;

int main() {
    cout << "\n--------------- LinkedList Test: HasLoopTest ---------------\n";
    
    LinkedList list(1); // LinkedList starts with one node with value 1.

    // Append some more nodes
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    // Test for no loop
    cout << "Before creating loop:\n";
    cout << "Has loop? " << (list.hasLoop() ? "Yes" : "No") << endl;

    // Create a loop by making the next node of the 
    // last node (5) point to the second node (2)
    list.getTail()->next = list.getHead()->next;

    // Test for loop existence
    cout << "\nAfter creating loop:\n";
    cout << "Has loop? " << (list.hasLoop() ? "Yes" : "No") << endl;

    cout << "------------- End of LinkedList Test: HasLoopTest ------------\n\n";
}


