#include <bits/stdc++.h>
using namespace std;

bool f(int ind, int k, vector<int> arr, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return true;
    }

    if (ind == 0)
    {
        return arr[ind] == k;
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    bool notTake = f(ind - 1, k, arr, dp);
    bool take = false;
    if (arr[ind] <= k)
    {
        take = f(ind - 1, k - arr[ind], arr, dp);
    }

    return dp[ind][k] = take | notTake;
}

int main()
{
    vector<int> arr{1, 2, 3, 5};
    int n = 4;
    int k = 7;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    cout << f(n - 1, k, arr, dp);
}