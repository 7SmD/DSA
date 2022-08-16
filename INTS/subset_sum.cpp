#include <bits/stdc++.h>
using namespace std;

int dp[51][51];

bool isSubsetSum(int i, vector<int> &nums, int n, int sum)
{
    if (i >= n)
    {
        return false;
    }

    if (sum == 0)
    {
        return true;
    }

    if (dp[i][sum]!=-1){
        return dp[i][sum];
    }

    int t = false, nt = false;

    if (nums[i] <= sum)
    {
        t = isSubsetSum(i + 1, nums, n, sum - nums[i]);
    }
    nt = isSubsetSum(i + 1, nums, n, sum);

    return  dp[i][sum] = t || nt;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 39;
    int n = nums.size();
    if (isSubsetSum(0, nums, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}
