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

Node* LinkedList::getTail() {
    return tail;
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
}

Node* LinkedList::findKthFromEnd(int k) {

    Node * end = head;
    Node* kth = head;

    if( k== 1){

        return tail;
    }


 
 while (end !=tail)
 {

    end= end->next;
    k--;

    if(k<1)
    {
        kth=kth->next;
    }
 }
 return kth;
 
/*
    for (int i = 0; i <= k-1 ; i++)
    {
        end= end->next;
        if (end == nullptr && i<= k-1){
            return nullptr;
        }
    }

    while (end)
    {
       end=end->next;
       kth= kth->next;
    }

    return kth;
    */
}

