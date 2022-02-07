#include <iostream>
using namespace std;

int fibo_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);
    ans[n] = a + b;

    return ans[n];
}

int fibo(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    return fibo_helper(n, ans);
}

int fibo_DP(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main()
{
    cout << fibo_DP(6);
}