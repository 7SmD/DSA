#include <bits/stdc++.h>
using namespace std;

int pathSum(int i, int j, vector<vector<int>> arr, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
    {
        return arr[i][j];
    }
    if (i < 0 || j < 0)
    {
        return INT8_MAX;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = arr[i][j] + pathSum(i - 1, j, arr, dp);
    int left = arr[i][j] + pathSum(i, j - 1, arr, dp);

    return dp[i][j] = min(up, left);
}

int main()
{
    int m = 3;
    int n = 3;

    vector<vector<int>> arr{{0, 0, -7},
                            {0, -1, 0},
                            {0, 0, 0}};

    vector<vector<int>>
        dp(m, vector<int>(n, -1));
    cout << pathSum(m - 1, n - 1, arr, dp);
}