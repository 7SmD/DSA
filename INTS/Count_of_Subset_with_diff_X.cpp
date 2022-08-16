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

    if (dp[i][t] != -1)
    {
        return dp[i][t];
    }

    return dp[i][t] = f(nums, i + 1, t - nums[i], n) + f(nums, i + 1, t, n);
}

int main()
{
    memset(dp, -1, sizeof(dp));

    vector<int> nums = {1,3};
    int n = nums.size();
    int sum = 0;
    
    for (auto i : nums)
    {
        sum += i;
    }
    
    int diff = 1;

    // s1-s2=diff    --> 1
    // s1+s2=sum     --> 2
    //  1 + 2
    // s1 = (sum+diff)/2

    int s1=(sum+diff)/2;

    cout << f(nums, 0, s1, n);

}
