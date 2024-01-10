
#include <iostream>
class Node
{

public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {

        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {

        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList()
    {

        Node *temp = head;
        while (temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    int getLength()
    {

        return length;
    }

    ~DoublyLinkedList()
    {

        Node *temp = head;

        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(int value)
    {

        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deletLast()
    {

        if (head == nullptr)
        {

            return;
        }

        Node *temp = tail;

        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = temp->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void deletFirst()
    {

        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {

            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value)
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
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    Node *get(int index)
    {

        if (index < 0 || index >= length)
            return nullptr;
        Node *temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; ++i)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; --i)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value)
    {

        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {

        if (index < 0 || index > length)
            return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }

        Node *newNode = new Node(value);
        Node *before = get(index - 1);
        Node *after = before->next;
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
        return true;
    }

    void deletNode(int index)
    {

        if (index < 0 || index >= length)
            return;
        if (index == 0)
            return deletFirst();
        if (index == length - 1)
            return deletLast();

        Node *temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
};

int main()
{

    DoublyLinkedList *ddl = new DoublyLinkedList(10);
    ddl->printList();
    std::cout << "------------" << std::endl;
    ddl->append(20);
    ddl->printList();
    std::cout << "------------" << std::endl;
    ddl->append(30);
    ddl->printList();
    std::cout << "------------" << std::endl;
    std::cout << ddl->getLength() << std::endl;
    ddl->deletLast();
    ddl->deletLast();
    ddl->printList();
    std::cout << ddl->getLength() << std::endl;
    std::cout << "------------" << std::endl;
    ddl->deletNode(2);
    ddl->printList();
}