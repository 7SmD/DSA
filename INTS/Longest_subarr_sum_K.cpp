#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int i = 0, j = 0, s = 0, ans = 0;
    int n = nums.size(),maxi=-1;

    while (j < n)
    {
        s += nums[j];

        if (s < k)
        {
            j++;
        }
        if (s == k)
        {
            maxi=max(maxi,j-i+1);
            j++;
        }

        if (s > k)
        {
            while (s > k)
            {
                s -= nums[i];
                i++;
            }

            j++;
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9, 1, 1 ,1 ,1 ,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    cout<< subarraySum(arr,k);
}
