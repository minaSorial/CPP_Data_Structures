#include <iostream>
#include "LinkedList.h"

using namespace std;

Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    length = 1;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

Node* LinkedList::getHead() {
    return head;
}

int LinkedList::getLength() {
    return length;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    length++;
}


    // FINISH THE PARTITIONLIST MEMBER FUNCTION HERE //
    



   void LinkedList::partitionList(int x) {
    if (head == nullptr) return;
 
    Node dummy1(0);
    Node dummy2(0);
    Node* prev1 = &dummy1;
    Node* prev2 = &dummy2;
    Node* current = head;
 
    while (current != nullptr) {
        if (current->value < x) {
            prev1->next = current;
            prev1 = current;
        } else {
            prev2->next = current;
            prev2 = current;
        }
        current = current->next;
    }
 
    prev2->next = nullptr;
    prev1->next = dummy2.next;
 
    head = dummy1.next;
}


