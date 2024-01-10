#include "Stack.h"
#include <iostream>

using namespace std;


vector<int>& Stack::getStackVector() {
    return stackVector;
}

void Stack::printStack() {
    for (int i = stackVector.size() - 1; i >= 0; i--) {
        cout << stackVector[i] << std::endl;
    }
}

bool Stack::isEmpty() {
    return stackVector.size() == 0;
}

int Stack::peek() {
    if (isEmpty()) {
        return int();
    } else {
        return stackVector[stackVector.size() - 1];
    }
}

int Stack::size() {
    return stackVector.size();
}

void Stack::push(int value) {
    stackVector.push_back(value);


   
}



