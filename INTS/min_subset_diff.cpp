
#include <bits/stdc++.h>
using namespace std;
int dp[51][51];

int f(int i, vector<int> &nums, int n, int sum)
{
    if (i >= n || sum < 0)
    {
        return dp[i][sum] = 0;
    }

    if (sum == 0)
    {
        return dp[i][sum] = 1;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    int t = 0, nt = 0;

    t = f(i + 1, nums, n, sum - nums[i]);

    nt = f(i + 1, nums, n, sum);

    return dp[i][sum] = t || nt;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    vector<int> nums = {3, 1, 4, 2, 2, 1};
    int n = nums.size();
    int range = 0;
    for (auto i : nums)
    {
        range += i;
    }

    int x = f(0, nums, n, range);

    int mini = 1000;

    for (int j = 0; j <= range / 2; j++)
    {
        if (dp[n][j] != -1)
        {
            mini = min(mini, range - 2 * j);
        }
    }
    cout << mini;
    return 0;
}
