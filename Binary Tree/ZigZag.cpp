#include <iostream>
using namespace std;
#include <queue>
#include <stack>

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

void levelOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() != 0)
    {

        if (q.front() == NULL)
        {
            q.pop();
            if (q.size() == 0)
            {
                break;
            }
            q.push(NULL);
            cout << endl;
        }

        if (q.front()->left)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right)
        {
            q.push(q.front()->right);
        }

        cout << q.front()->data << " ";

        q.pop();
    }
}

void zigZagOrder(BinaryTreeNode<int> *root)
{

    if (!root)
        return;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    s1.push(root);

    while (!s1.empty() && !s1.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";

            if (top->left)
                s2.push(top->left);
            if (top->right)
                s2.push(top->right);
        }

        cout << endl;

        while (!s2.empty())
        {
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";

            if (top->right)
                s1.push(top->right);
            if (top->left)
                s1.push(top->left);
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);

    cout << endl;

    zigZagOrder(root);
}