#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
        Node* findMiddleNode();
};

#endif //LINKED_LIST_H
