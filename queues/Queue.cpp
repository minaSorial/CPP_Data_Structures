#include<iostream>

class Node{

    public:
    int value ;
    Node* next;

    Node(int value):value(value), next(nullptr){
    
    }
};

class Queue
{
private:
  
  Node* first;
  Node* last;
  int  lenght;
public:
    Queue(int value){

        Node *newNode= new Node(value);
        first= newNode;
        last=newNode;
        lenght=1;

    }
    ~Queue() {

        Node* temp= first;
        while (first)
        {
            first=first->next;
            delete temp;
            temp=first;
        }
        

    }

    void enqueue(int value){
        Node* newNode = new Node(value);

        if (lenght==0)
        {
            first=newNode;
            last=newNode;

        }else{

            last->next= newNode;
            last=newNode;
        }
        lenght++;
        

    }

    int dequeue(){

        if (first==nullptr) return INT_MIN;
        Node* temp= first;
        int dequeuedValue= first->value;
        if(lenght==1){
            first=nullptr;
            last= nullptr;

        }else{

            first= first->next;
        }
        delete temp;
        lenght--;
        return dequeuedValue; 
    }
    
    void printQueue(){

        Node* temp= first;
        while (temp)
        {
                std::cout<<temp->value<<std::endl;
                temp=temp->next;
        }
        

    }

};






int main(){

Queue* myQ = new Queue(10);
myQ->printQueue();

}