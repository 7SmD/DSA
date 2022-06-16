#include <bits/stdc++.h>
using namespace std;

int nin(int day, int last, vector<vector<int>> arr, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, arr[0][task]);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int p = arr[day][task] + nin(day - 1, task, arr, dp);
            maxi = max(maxi, p);
        }
    }

    return dp[day][last] = maxi;
}

int main()
{
    vector<vector<int>> arr{{18, 11, 19},
                            {4, 13, 7},
                            {1, 8, 13}};
    int n = 3;
    vector<vector<int>> dp(n, vector<int>(4, -1));

    cout << nin(n - 1, 3, arr, dp);
}
