#include <iostream>
using namespace std;
#include <queue>
#include <cmath>

template <typename T>

class BinaryTreeNode
{

public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";

    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

void searchBSTinRange(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > min)
    {
        searchBSTinRange(root->left, min, max);
    }

    if (min <= root->data && root->data <= max)
    {
        cout << root->data << " ";
    }

    if (root->data <= max)
    {
        searchBSTinRange(root->right, min, max);
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);

    int min, max;
    cout << "Enter the range to be searched : ";
    cin >> min >> max;

    searchBSTinRange(root, min, max);

    delete root;
}