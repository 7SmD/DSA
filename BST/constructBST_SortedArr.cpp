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

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT8_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT8_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

BinaryTreeNode<int> *tree(int *input, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = tree(input, start, mid - 1);
    root->right = tree(input, mid + 1, end);

    return root;
}

BinaryTreeNode<int> *constructTree(int *arr, int n)
{
    return tree(arr, 0, n - 1);
}

int main()
{
    //BinaryTreeNode<int> *root = takeInputLevelWise();
    int n, data;
    cout << "No. of elements : ";
    cin >> n;
    int input[n];
    cout << "Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        input[i] = data;
    }

    BinaryTreeNode<int> *root = constructTree(input, n);
    printTree(root);

    delete root;
}