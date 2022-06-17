#include <bits/stdc++.h>
using namespace std;

int pathSum(int i, int j, vector<vector<int>> arr, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        return arr[i][j];
    }
    if (j >= arr[0].size() || j < 0)
    {
        return INT8_MIN;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = arr[i][j] + pathSum(i - 1, j, arr, dp);
    int dl = arr[i][j] + pathSum(i - 1, j - 1, arr, dp);
    int dr = arr[i][j] + pathSum(i - 1, j + 1, arr, dp);

    return dp[i][j] = max(dr, max(up, dl));
}

int main()
{
    int m = 3;
    int n = 3;

    vector<vector<int>> arr{{1, 0, 7},
                            {0, 1, 0},
                            {2, 0, 1}};

    vector<vector<int>>
        dp(m, vector<int>(n, -1));

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, pathSum(m - 1, i, arr, dp));
    }

    cout << maxi;
}