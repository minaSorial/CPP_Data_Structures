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

Node* LinkedList::findMiddleNode() {
  
  Node* temp= head;
    int length= 0;
  while(temp){

    temp=temp->next;
    length++;
  }

  temp=head;
  for(int i=0; i<(length/2);i++){
    temp=temp->next;

  }

  return temp;
}

