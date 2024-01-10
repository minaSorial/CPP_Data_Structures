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
        int length;

    public:
        LinkedList(int value);
        ~LinkedList();
        void printList();
        Node* getHead();
        int getLength();
		void append(int value);
		void partitionList(int x);
};

#endif // LINKEDLIST_H
