#include <bits/stdc++.h>
using namespace std;

int pathSum(int i, int j, vector<vector<int>> arr, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && arr[i][j] == -1)
    {
        return 0;
    }
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

    int up = pathSum(i - 1, j, arr, dp);
    int left = pathSum(i, j - 1, arr, dp);

    return dp[i][j] = up + left;
}

int main()
{
    int m = 2;
    int n = 2;

    vector<vector<int>> arr{{0, 0},
                            {-1, 0}};

    vector<vector<int>>
        dp(m, vector<int>(n, -1));
    cout << pathSum(m - 1, n - 1, arr, dp);
}