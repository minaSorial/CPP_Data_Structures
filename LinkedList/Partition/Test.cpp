#include <iostream> 
#include "LinkedList.h"

using namespace std;

int main() {
    // Test 1: SingleElementList
    {
        cout << "\n------------ LinkedList Test: SingleElementListTest ------------\n";
        LinkedList list(5);
        cout << "Before partitioning with x=3:\n";
        list.printList();
        list.partitionList(3);
        cout << "After partitioning:\n";
        list.printList();
    }

    // Test 2: ListWithValuesLessThanX
    {
        cout << "\n---------- LinkedList Test: ListWithValuesLessThanX Test ----------\n";
        LinkedList list(1);
        list.append(2);
        list.append(3);
        cout << "Before partitioning with x=4:\n";
        list.printList();
        list.partitionList(4);
        cout << "After partitioning:\n";
        list.printList();
    }

    // Test 3: ListWithValuesGreaterThanX
    {
        cout << "\n--------- LinkedList Test: ListWithValuesGreaterThanX Test ---------\n";
        LinkedList list(5);
        list.append(6);
        list.append(7);
        cout << "Before partitioning with x=4:\n";
        list.printList();
        list.partitionList(4);
        cout << "After partitioning:\n";
        list.printList();
    }

    // Test 4: ListWithValuesMixedAroundX
    {
        cout << "\n--------- LinkedList Test: ListWithValuesMixedAroundX Test ---------\n";
        LinkedList list(3);
        list.append(2);
        list.append(1);
        list.append(5);
        list.append(4);
        cout << "Before partitioning with x=3:\n";
        list.printList();
        list.partitionList(3);
        cout << "After partitioning:\n";
        list.printList();
    }
}


/* 
    EXPECTED OUTPUT:
    ------------ LinkedList Test: SingleElementListTest ------------
    Before partitioning with x=3:
    5
    After partitioning:
    5
    ---------- LinkedList Test: ListWithValuesLessThanX Test ----------
    Before partitioning with x=4:
    1
    2
    3
    After partitioning:
    1
    2
    3
    --------- LinkedList Test: ListWithValuesGreaterThanX Test ---------
    Before partitioning with x=4:
    5
    6
    7
    After partitioning:
    5
    6
    7
    --------- LinkedList Test: ListWithValuesMixedAroundX Test ---------
    Before partitioning with x=3:
    3
    2
    1
    5
    4
    After partitioning:
    2
    1
    3
    5
    4
    
*/

