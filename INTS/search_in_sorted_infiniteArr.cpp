#include <bits/stdc++.h>
using namespace std;

int findPos(vector<int> &arr, int t)
{
    int l = 0, r = l + 2;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == t)
        {
            return m;
        }
        else if (arr[m] < t)
        {
            l = m + 1;
            r = 2 * r;
        }
        else if (arr[m] > t)
        {
            r = m - 1;
        }
    }

    return -1;
}
int main()
{
    vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130,
                       140, 160, 170};
    int ans = findPos(arr, 90);
    cout << "Element ind : " << ans;
    return 0;
}
