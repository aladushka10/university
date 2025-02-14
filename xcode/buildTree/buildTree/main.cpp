#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int key;
};

void add(int key, Node* node)
{
    Node* parent = nullptr;
    while (node != nullptr)
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

void PreOrderTravel(Node* node)
{
    if(node == nullptr)
        return ;
    cout << node->key << endl;
    PreOrderTravel(node->left);
    PreOrderTravel(node->right);
}

int main() {
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    int x;
    Node* root = nullptr;
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
    PreOrderTravel(root);
    return 0;
}
