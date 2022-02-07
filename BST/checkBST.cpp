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

/*
bool isBST(BinaryTreeNode<int> *root)
{
    if(root==NULL){
        return true;
    }

    int leftmax=maximum(root->left);
    int rightmin=minimum(root->right);

    bool output=(root->data > leftmax) && (root->data < rightmin) && isBST(root->left) && isBST(root->right);
    return output;
}



class isBSTreturn
{
public:
    int maximum;
    int minimum;
    bool bst;
};

isBSTreturn bst2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isBSTreturn op;
        op.maximum = INT8_MIN;
        op.minimum = INT8_MAX;
        op.bst = true;

        return op;
    }

    isBSTreturn leftOp = bst2(root->left);
    isBSTreturn rightOp = bst2(root->right);

    int Max = max(root->data, max(leftOp.maximum, rightOp.maximum));
    int Min = min(root->data, min(leftOp.minimum, rightOp.minimum));
    bool isBstFinal = (root->data > leftOp.maximum) && (root->data <= rightOp.minimum) && leftOp.bst && rightOp.bst;

    isBSTreturn obj;
    obj.minimum = Min;
    obj.maximum = Max;
    obj.bst = isBstFinal;
    return obj;
}

*/

bool isBST3(BinaryTreeNode<int> *root, int min = INT8_MAX, int max = INT8_MIN)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool isLeftOK = isBST3(root->left, min, root->data - 1);
    bool isRightOK = isBST3(root->right, root->data, max);

    return isLeftOK && isRightOK;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);

    // isBSTreturn ans= bst2(root);
    // cout<<ans.bst;
    cout << isBST3(root);

    delete root;
}