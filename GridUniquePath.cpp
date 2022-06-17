#include <bits/stdc++.h>
using namespace std;

int maze(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = maze(i - 1, j, dp);
    int left = maze(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << maze(m - 1, n - 1, dp);
}