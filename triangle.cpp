#include <bits/stdc++.h>
using namespace std;

int tri(int i, int j, vector<vector<int>> arr, vector<vector<int>> &dp, int n)
{

    if (i == n - 1)
    {
        return arr[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int d = arr[i][j] + tri(i + 1, j, arr, dp, n);
    int dg = arr[i][j] + tri(i + 1, j + 1, arr, dp, n);

    return dp[i][j] = min(d, dg);
}

int main()
{

    int n = 3;

    vector<vector<int>> arr{{5},
                            {1, 2},
                            {3, 1, 5}};

    vector<vector<int>>
        dp(n, vector<int>(n, -1));
    cout << tri(0, 0, arr, dp, n);
}