#include <iostream> 
#include "LinkedList.h"

using namespace std;

int main() {
    cout << "\n----------- LinkedList Test: FindKthFromEndTest -----------\n";
    
    LinkedList list(1); // LinkedList starts with one node with value 1.

    // Append some more nodes
    for (int i = 2; i <= 5; ++i) {
        list.append(i);
    }

    // Test when k is 1 (expect last element)
    Node* node = list.findKthFromEnd(1);
    cout << "When k is 1, node value is " << node->value << endl;

    // Test when k is exactly the length (expect first element)
    node = list.findKthFromEnd(5);
    cout << "When k is 5, node value is " << node->value << endl;

    // Test for a general case
    node = list.findKthFromEnd(4);
    cout << "When k is 4, node value is " << node->value << endl;

    cout << "-------- End of LinkedList Test: FindKthFromEndTest --------\n\n";
}


/* 
    EXPECTED OUTPUT:
    ----------- LinkedList Test: FindKthFromEndTest -----------
    When k is 1, node value is 5
    When k is 5, node value is 1
    When k is 4, node value is 2
    -------- End of LinkedList Test: FindKthFromEndTest --------
    
*/