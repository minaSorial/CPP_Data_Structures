#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    cout << "\n------------ LinkedList Test: FindMiddleNodeTest ------------\n";
    
    LinkedList list(1);  // LinkedList starts with one node with value 1.
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    // Finding the middle node
    Node* middle = list.findMiddleNode();
    cout << "Middle node value of a 5-node list: " << middle->value << endl;

    // Adding another node
    list.append(6);

    // Finding the middle node again
    middle = list.findMiddleNode();
    cout << "Middle node value of a 6-node list: " << middle->value << endl;

    cout << "\n--------- End of LinkedList Test: FindMiddleNodeTest ---------\n";
}


/* 
    EXPECTED OUTPUT:
    ------------ LinkedList Test: FindMiddleNodeTest ------------
    Middle node value of a 5-node list: 3
    Middle node value of a 6-node list: 4
    --------- End of LinkedList Test: FindMiddleNodeTest ---------
    
*/