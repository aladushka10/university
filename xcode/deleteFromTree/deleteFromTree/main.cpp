#include <iostream>
#include <fstream>
using namespace std;

//ofstream fout("output.txt");

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int key;
};

Node* root = nullptr;

void replaceChild(Node* parent, Node* child, Node* newChild)
{
    if(parent == nullptr)
        root = newChild;
    else
        if(child == parent->right)
            parent->right = newChild;
        else
            parent->left = newChild;
}

void deleteKey(int key, Node* node)
{
    Node* parent = nullptr;
    while(key != node->key)
    {
        parent = node;
        if(key > node->key)
            node = node->right;
        else
            node = node->left;
        if(node == nullptr)
            return ;
    }
    
    if(node->right == nullptr)
    {
        replaceChild(parent, node, node->left);
        delete node;
    }
    else
        if(node->left == nullptr)
        {
            replaceChild(parent, node, node->right);
            delete node;
        }
        else
        {
            Node* minNode = node->right;
            Node* parentMinNode = node;
            while(minNode->left != nullptr)
            {
                parentMinNode = minNode;
                minNode = minNode->left;
            }
            node->key = minNode->key;
            replaceChild(parentMinNode, minNode, minNode->right);
            delete minNode;
        }
}

void add(int key, Node* node)
{
    Node* parent = nullptr;
    while(node != nullptr)
    {
        parent = node;
        if(key > node->key)
            node = node->right;
        else
            if(key < node->key)
                node = node->left;
            else
                return ;
    }
    Node* newNode = new Node;
    newNode->key = key;
    if(key > parent->key)
        parent->right = newNode;
    else
        parent->left = newNode;
}

/*void PreOrderTraversal(Node* node)
{
    if(node == nullptr)
        return ;
    cout << node->key << endl;
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}*/

int main() {
    //ifstream fin("input.txt");
    int key, x;
    cin >> key;
    while(cin >> x)
    {
        if(root == nullptr)
        {
            Node* newNode = new Node;
            newNode->key = x;
            root = newNode;
        }
        else
            add(x, root);
    }
    return 0;
}
