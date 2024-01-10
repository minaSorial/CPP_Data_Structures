#ifndef STACK_H
#define STACK_H

#include <vector>

using std::vector;

class Stack {
private:
    vector<int> stackVector;

public:
    vector<int>& getStackVector();
    void printStack();
    bool isEmpty();
    int peek();
    int size();
    void push(int value);
};

#endif /* STACK_H */