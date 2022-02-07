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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
    {
        return false;
    }
    if (root1->data != root2->data || root1->children.size() != root2->children.size())
    {
        return false;
    }
    int i = 0;
    while (i < root1->children.size())
    {

        TreeNode<int> *child1 = root1->children[i];
        TreeNode<int> *child2 = root2->children[i];
        if (isIdentical(child1, child2))
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    TreeNode<int> *root1 = takeInputLevelwise();
    printTree(root1);
    TreeNode<int> *root2 = takeInputLevelwise();
    printTree(root2);
    int ans = isIdentical(root1, root2);
    if (ans == 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}