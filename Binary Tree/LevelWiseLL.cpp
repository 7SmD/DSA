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

BinaryTreeNode<int> *remLeaf(BinaryTreeNode<int> *root)
{

    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    if (root->left)
    {
        root->left = remLeaf(root->left);
    }
    if (root->right)
    {
        root->right = remLeaf(root->right);
    }

    return root;
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

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

vector<node *> createLLForEachLevel(BinaryTreeNode<int> *root)
{

    vector<node *> v;

    if (root == NULL)
    {
        v.push_back(NULL);

        return v;
    }

    queue<BinaryTreeNode<int> *> pn;

    pn.push(root);
    pn.push(NULL);

    node *head = NULL;
    node *tail = head;

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();

        if (front == NULL)
        {
            tail->next = NULL;

            if (pn.size() == 0)
                break;

            pn.push(NULL);

            head = NULL;
            tail = NULL;
        }

        else
        {
            node *n = new node(front->data);
            if (head == NULL)
            {
                head = tail = n;
                v.push_back(head);
            }
            else
            {
                tail->next = n;
                tail = n;
            }

            if (front->left)
                pn.push(front->left);
            if (front->right)
                pn.push(front->right);
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    printLevelWise(root);

    cout << endl;

       levelOrder(root);
}