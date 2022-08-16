#include <bits/stdc++.h>
using namespace std;

int dp[51][51];

int f(vector<int> &nums, int i, int t, int n)
{
    if (t == 0)
    {
        return 1;
    }
    if (i >= n || t < 0)
    {
        return 0;
    }

    if(dp[i][t]!=-1){
        return dp[i][t];
    }

    return dp[i][t] = f(nums, i + 1, t - nums[i], n) + f(nums, i + 1, t, n);
}

int main()
{
    memset(dp,-1,sizeof(dp));

    vector<int> nums = {3, 3, 3, 3};
    int n = nums.size();
    int x = 6;

    cout << f(nums, 0, x, n);

    return 0;
}
