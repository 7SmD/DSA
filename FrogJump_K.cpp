#include <bits/stdc++.h>
using namespace std;

int jump(int n, int arr[], vector<int> &dp, int k) // memoization TOP -> DOWN
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int mmm = INT8_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
        {
            int sub = jump(n - i, arr, dp, k) + abs(arr[n] - arr[n - i]);
            mmm = min(sub, mmm);
        }
    }

    return dp[n] = mmm;
}

int main()
{
    int arr[] = {30, 10, 60, 10, 60, 50};
    int n = 6;
    int k = 2;
    vector<int> dp(n + 1, -1);

    cout << jump(n - 1, arr, dp, k);
}
