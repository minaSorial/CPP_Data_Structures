#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node { 
    public:
        int value;
        Node* next;
        Node(int value);
}; 

class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(int value);
        ~LinkedList();
        void printList();
        Node* getHead();
        Node* getTail();
        void append(int value);
        Node* findKthFromEnd(int k);
};

#endif // LINKEDLIST_H
