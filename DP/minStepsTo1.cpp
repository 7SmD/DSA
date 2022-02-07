#include <iostream>
using namespace std;
#include <cmath>

//recursive

int minSteps(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int y = INT8_MAX, z = INT8_MAX;
    int x = minSteps(n - 1);
    if (n % 2 == 0)
    {
        y = minSteps(n / 2);
    }
    if (n % 3 == 0)
    {

        z = minSteps(n / 3);
    }

    int ans = min(x, min(y, z)) + 1;
    return ans;
}

//Memoization

int minStepsHelper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int y = INT8_MAX, z = INT8_MAX;

    int x = minStepsHelper(n - 1, ans);
    if (n % 2 == 0)
    {
        y = minStepsHelper(n / 2, ans);
    }
    if (n % 3 == 0)
    {

        z = minStepsHelper(n / 3, ans);
    }

    int output = min(x, min(y, z)) + 1;

    ans[n] = output;

    return output;
}

int minSteps_2(int n)
{

    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    return minStepsHelper(n, ans);
}

int main()
{
    cout << minSteps(11)<<endl;
    cout << minSteps_2(11);
}