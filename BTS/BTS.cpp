#include <iostream>

class Node
{

public:
    int value;
    Node *right;
    Node *left;

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
    Node *root;

public:
    BTS()
    {
        root = nullptr;
    }
    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
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
        Node *temp = root;
        while (temp != nullptr)
        {
            if (value < temp->value){
                temp = temp->left;
            }else if (value > temp->value){
                temp = temp->right;
            }else{
                return true;
            }
        }
        return false;
    }
    ~BTS();
};

int main()
{

    BTS *myBTS = new BTS();
    myBTS->insert(47);
    myBTS->insert(21);
    myBTS->insert(76);
    myBTS->insert(18);
    myBTS->insert(52);
    myBTS->insert(82);

    myBTS->insert(27);

    std::cout << myBTS->root->left->right->value << std::endl;

    std::cout<< myBTS->contains(82)<<std::endl;
    std::cout<< myBTS->contains(81)<<std::endl;

}
