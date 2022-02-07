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

BinaryTreeNode<int> *binaryTreeHelper(int *postOrder, int *inOrder, int poS, int poE, int inS, int inE)
{
    if (poS > poE || inS > inE)
    {
        return nullptr;
    }
    int rootData = postOrder[poE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPoS = poS;
    int leftPoE = poS + rootIndex - inS - 1;
    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPoS = leftPoE + 1;
    int rightPoE = poE - 1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = binaryTreeHelper(postOrder, inOrder, leftPoS, leftPoE, leftInS, leftInE);
    root->right = binaryTreeHelper(postOrder, inOrder, rightPoS, rightPoE, rightInS, rightInE);
    return root;
}
BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{

    return binaryTreeHelper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}

int main()
{
    /*
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);

    cout << endl;

    printLevelWise(root);
    */
}