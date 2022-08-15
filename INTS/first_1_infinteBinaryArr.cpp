
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &arr)
{

    if (arr[0] == 1)
    {
        return 0;
    }

    int n = arr.size(), l = 0, r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == 1 && arr[m - 1] == 0)
        {
            return m;
        }
        else if (arr[m] < 1)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    cout << "Index = " << f(arr);
}
