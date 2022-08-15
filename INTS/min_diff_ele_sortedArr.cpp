
#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> &arr, int n, int t)
{
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == t)
        {
            return 0;
        }
        else if (arr[m] > t)
        {
            r = m - 1;
        }
        else if (arr[m] < t)
        {
            l = m + 1;
        }
    }

    return min(abs(t - arr[r]), abs(t - arr[l]));
}

int main()
{
    vector<int> arr = {1, 3, 5, 17, 18, 25};
    int n = arr.size();
    int t = 19;
    cout << "Minimum difference is " << findMinDiff(arr, n, t);
    return 0;
}
