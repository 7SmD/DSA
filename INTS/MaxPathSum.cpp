#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int f(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }
        int l = f(root->left, res);
        int r = f(root->right, res);

        int temp = max(root->val + max(l, r), root->val);
        int ans = max(temp, root->val + l + r);
        res = max(res, ans);

        return temp;
    }

    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        f(root, res);
        return res;
    }
};