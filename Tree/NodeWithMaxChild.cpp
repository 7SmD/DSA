#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelwise()
{
    int rootData;
    cout << "Enter Data : " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the no. of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingQ;
    pendingQ.push(root);
    while (pendingQ.size() != 0)
    {
        TreeNode<int> *front = pendingQ.front();
        cout << front->data << " : ";
        pendingQ.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);

            if (root->children.size() - 1 != i)
            {
                cout << root->children[i]->data << " , ";
            }
            else
            {
                cout << root->children[i]->data;
            }
        }
        root = pendingQ.front();
        cout << endl;
    }
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *childmax = maxSumNode(root->children[i]);
        int smallSum = childmax->data;

        for (int i = 0; i < childmax->children.size(); i++)
        {
            smallSum += childmax->children[i]->data;
        }
        if (sum <= smallSum)
        {
            ans = childmax;
            sum = smallSum;
        }
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelwise();
    printTree(root);

    TreeNode<int> *node = maxSumNode(root);
    cout << "Node with Max child : " << node->data;
}