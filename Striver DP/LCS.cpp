#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, string &t1, string &t2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (t1[i] == t2[j])
        {
            return dp[i][j] = 1 + f(i - 1, j - 1, t1, t2, dp);
        }
        else
        {
            return dp[i][j] = max(f(i - 1, j, t1, t2, dp), f(i, j - 1, t1, t2, dp));
        }
    }

    int longestCommonSubsequence(string t1, string t2)
    {
        int m = t1.size();
        int n = t2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, t1, t2, dp);
    }
};
