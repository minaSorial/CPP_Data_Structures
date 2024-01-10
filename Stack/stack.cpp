#include <iostream>
class Node
{

public:
    int value;
    Node *next;

    Node(int value)
    {

        this->value = value;
        next = nullptr;
    }
};

class stack
{
private:
    Node *top;
    int height;

public:
    stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }
    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    void push(int value)
    {

        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }
    int pop(){
        if (top==nullptr)
        {
            return INT_MIN ;

        }else{

            Node* temp= top;
            int poppedValue= temp->value;
            top=top->next;
            delete temp;
            height--;
            return  poppedValue;
        }
        


    }
    

    ~stack()
    {

        Node *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
            std::cout << "in destructor" << std::endl;
        }
    }

    int getHeight()
    {
        return height;
    }
};

int main()
{

    stack *newStack = new stack(9);
    newStack->printStack();
    newStack->push(20);
    newStack->push(30);


    std::cout<<"-----------" << std::endl;
    newStack->printStack();
    std::cout<<"-----------" << std::endl;
    std::cout<< newStack->pop()<<std::endl;
    std::cout<<"-----------" << std::endl;
    newStack->printStack();
    std::cout<< newStack->pop()<<std::endl;
     std::cout<< newStack->pop()<<std::endl;
      std::cout<< newStack->pop()<<std::endl;
std::cout<<"-----------" << std::endl;
  
    newStack->push(30);
      newStack->printStack();
      std::cout<< newStack->getHeight()<<std::endl;

}
