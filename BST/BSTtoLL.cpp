#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    // cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        // cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        // cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

Node<int> *constructBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        Node<int> *output = new Node<int>(root->data);
        return output;
    }
    Node<int> *output = new Node<int>(root->data);
    Node<int> *leftOutput = constructBST(root->left);
    Node<int> *rightOutput = constructBST(root->right);
    if (leftOutput != NULL)
    {
        Node<int> *temp = leftOutput;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = output;
    }
    output->next = rightOutput;
    if (leftOutput == NULL)
        return output;
    return leftOutput;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Node<int> *head = constructBST(root);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}