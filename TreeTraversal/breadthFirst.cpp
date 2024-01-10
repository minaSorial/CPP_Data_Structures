#include <iostream>
#include<queue>
using namespace  std;



class Node
{

public:
    int value;
    Node* right;
    Node* left;

    Node(int value)
    {

        this->value = value;
        right = nullptr;
        left = nullptr;
    }
};


class BTS
{
public:
    Node* root;

public:
    BTS()
    {
        root = nullptr;
    }
    bool insert(int value)
    {
        Node* newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {

                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value)
    {
        /*
        if (root == nullptr)
        {
            return false;
        }
        */
        Node* temp = root;
        while (temp != nullptr)
        {
            if (value < temp->value) {
                temp = temp->left;
            }
            else if (value > temp->value) {
                temp = temp->right;
            }
            else {
                return true;
            }
        }
        return false;
    }


    void BFS() {

        std::cout << " Breadth first :";
        queue<Node*> myQueue;
        myQueue.push(root);
        while (myQueue.size() > 0)
        {
            Node* currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";

            if (currentNode->left != nullptr) {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                myQueue.push(currentNode->right);
            }

        }
        std::cout << endl;

    }

    void DFSPreorder(Node* currentNode) {

        cout << currentNode->value << " ";
        if (currentNode->left)
        {
            DFSPreorder(currentNode->left);
        }if (currentNode->right) {
            DFSPreorder(currentNode->right);
        }
    }
    void DFSPreorder() {
        std::cout << " PreOrder traversal :";
        DFSPreorder(root);
        std::cout << endl;
    }

    void DFSPostOrder() {
        std::cout << " PostOrder traversal :";
        DFSPostOrder(root);
        std::cout << endl;
    }

    void DFSPostOrder(Node* currentNode) {

        if (currentNode->left)
        {
            DFSPostOrder(currentNode->left);
        }if (currentNode->right) {
            DFSPostOrder(currentNode->right);
        }

        cout << currentNode->value << " ";

    }


    void DFSInOrder(Node* currentNode) {


        if (currentNode->left)
        {
            DFSInOrder(currentNode->left);
        }
        cout << currentNode->value << " ";

        if (currentNode->right) {
            DFSInOrder(currentNode->right);
        }


    }
    void DFSInOrder() {
        std::cout << " InOrder traversal :";
        DFSInOrder(root);
        std::cout << endl;

    }







    ~BTS();
};







int main() {


    BTS* myTree = new BTS();
    myTree->insert(47);
    myTree->insert(21);
    myTree->insert(76);
    myTree->insert(18);
    myTree->insert(27);
    myTree->insert(52);
    myTree->insert(82);

    myTree->BFS();
    myTree->DFSPreorder();
    myTree->DFSPostOrder();
    myTree->DFSInOrder();





}