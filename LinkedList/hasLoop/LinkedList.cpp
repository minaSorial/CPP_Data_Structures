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
    tail = newNode;
    length = 1;
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

Node* LinkedList::getTail() {
    return tail;
}

int LinkedList::getLength() {
    return length;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

bool LinkedList::hasLoop() {
    
    Node * slow= head;
    Node * fast= head;

    while (slow && fast&&slow->next && fast->next)
    {
        slow= slow->next;
        fast= fast->next->next;
        if(slow== fast){
            return true;
        } 
    }
    return false;

}
