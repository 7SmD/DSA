#include <iostream>
using namespace std;
#include <queue>

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
    cout << "Enter root data : ";
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
        cout << "Enter left child of " << currentNode->data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode->data << " : ";
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

#include <queue>

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pending;
    pending.push(root);
    while (pending.size() != 0)
    {
        cout << pending.front()->data << ":";
        if (pending.front()->left == NULL)
        {
            cout << "L:-1,";
        }
        if (pending.front()->left != NULL)
        {
            cout << "L:" << pending.front()->left->data << ",";
            pending.push(pending.front()->left);
        }
        if (pending.front()->right == NULL)
        {
            cout << "R:-1";
        }
        if (pending.front()->right != NULL)
        {
            cout << "R:" << pending.front()->right->data;
            pending.push(pending.front()->right);
        }
        cout << endl;
        pending.pop();
    }
}

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
    {
        return lh + 1;
    }
    else
    {
        return rh + 1;
    }
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    if ((height(root->left) - height(root->right) > 1) || (height(root->right) - height(root->left) > 1))
    {
        return false;
    }

    bool a = isBalanced(root->left);
    bool b = isBalanced(root->right);

    if (a && b)
    {
        return true;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);

    cout << endl;

    if (isBalanced(root))
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
}