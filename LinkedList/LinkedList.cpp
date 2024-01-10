#include <iostream>

class Node
{

public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    };

    void printList()
    {

        Node *temp = head;
        while (temp) // temp!=nullptr
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {

            tail->next = newNode;
            tail = newNode;
            // tail->next=nullptr;
        }

        length++;
    }

    void prePend(int value)
    {

        Node *newNode = new Node(value);

        if (head == nullptr)
        {

            head = newNode;
            tail = newNode;
        }
        else
        {

            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deletLast()
    {

        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        Node *pre = head;

        if (head->next == nullptr)
        {

            head = nullptr;
            tail = nullptr;
        }
        else
        {

            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }

            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void deleteFirst()
    {
        

        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {

            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {

            Node *temp = head->next;

            head = temp;
        }
        length--;
    }

    ~LinkedList()
    {

        Node *temp = head;

        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    };

    void getLength()
    {

        std::cout << "Lengths is " << length << std::endl;
    }

    Node *get(int index)
    {

        if (index < 0 || index >= length)
        {
            return nullptr;
        }

        Node *temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    bool set(int index, int value)
    {

        Node *temp = get(index);
        if (temp != nullptr)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            return false;
        }
        else if (index == 0)
        {
            prePend(value);
        }
        else if (index == length)
        {
            append(value);
        }
        else
        {
            Node *temp = get(index - 1);
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
        return true;
    }

    bool deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            return false;
        }
        else if (index == 0)
        {
            deleteFirst();
        }
        else if (index == length-1)
        {
            deletLast();
        }
        else
        {
            Node *pre =get(index-1);
            Node *temp = pre->next;
           
            pre->next=temp->next;
            delete temp;
            length--;
        }
        return true;
    }


    void reverse(){

        Node* temp= head;
        head= tail;
        tail=temp;

        Node * after = temp->next;
        Node * before = nullptr;

        for(int i = 0; i<length; i++){

            after= temp->next;
            temp->next= before;
            before= temp;
            temp=after;
        }
        

    }
};

int main()
{

    LinkedList *myLinkedList = new LinkedList(10);
    myLinkedList->append(20);
    myLinkedList->append(50);
    myLinkedList->append(30);

    myLinkedList->prePend(100);
    myLinkedList->printList();
    myLinkedList->getLength();

    myLinkedList->deletLast();
    myLinkedList->deleteFirst();

    myLinkedList->printList();
    myLinkedList->getLength();

    std::cout << "------------------" << std::endl;
    std::cout << myLinkedList->get(0)->value << std::endl;
    std::cout << myLinkedList->get(1)->value << std::endl;
    std::cout << myLinkedList->get(2)->value << std::endl;
    // std::cout << myLinkedList->get(3)->value << std::endl;
    myLinkedList->set(2, 2500);
    std::cout << "------------------" << std::endl;

    myLinkedList->insert(0, 155);
    myLinkedList->insert(4, 155);

    myLinkedList->insert(2, 155);

    myLinkedList->printList();
 std::cout << "------------------" << std::endl;

myLinkedList->deleteNode(0);
 std::cout << "------------------" << std::endl;
   myLinkedList->printList();
 std::cout << "------------------" << std::endl;
myLinkedList->deleteNode(4);
myLinkedList->printList();

 std::cout << "------------------" << std::endl;
myLinkedList->deleteNode(2);
myLinkedList->printList();

std::cout << "------------------" << std::endl;

myLinkedList->reverse();
myLinkedList->printList();
}



