#include <iostream>
using namespace std;
#include <cmath>

//recursive
int minCount(int n)
{
    if (n <= 3)
    {
        return n;
    }
    int ans = INT8_MAX;
    int i = 1;

    while ((i * i) <= n)
    {
        int x = minCount(n - (i * i));
        ans = min(x + 1, ans);
        i++;
    }
    return ans;
}

//DP
int minCount_helper_DP(int n, int *arr)
{
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    if (arr[n] != -1)
    {
        return arr[n];
    }

    for (int i = 4; i <= n; i++)
    {
        int ans = INT8_MAX;
        int j = 1;

        while ((j * j) <= i)
        {
            int x = minCount_helper_DP(i - (j * j), arr);
            ans = min(x + 1, ans);
            j++;
        }
        arr[i] = ans;
    }
    return arr[n];
}

int minCount_DP(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return minCount_helper_DP(n, arr);
}

int main()
{
    cout << minCount(21) << endl;
    cout << minCount_DP(21);
}