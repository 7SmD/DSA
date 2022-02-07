#include <iostream>
using namespace std;
#include <cmath>

//recursive
int minCostPath(int **input, int m, int n, int i, int j)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT8_MAX;
    }

    int x = minCostPath(input, m, n, i, j + 1);
    int y = minCostPath(input, m, n, i + 1, j + 1);
    int z = minCostPath(input, m, n, i + 1, j);

    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPath(input, m, n, 0, 0);
}

//Memoization
int minCostPath_mem(int **input, int m, int n, int i, int j, int **output)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT8_MAX;
    }

    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    int x = minCostPath_mem(input, m, n, i, j + 1, output);
    int y = minCostPath_mem(input, m, n, i + 1, j + 1, output);
    int z = minCostPath_mem(input, m, n, i + 1, j, output);

    int a = min(x, min(y, z)) + input[i][j];
    output[i][j] = a;

    return a;
}
int minCostPath_mem(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return minCostPath_mem(input, m, n, 0, 0, output);
}

//DP
int minCostPath_DP(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    output[m - 1][n - 1] = input[m - 1][n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = input[m - 1][j] + output[m - 1][j + 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }
    return output[0][0];
}

int main()
{
    int **arr, n, m;
    cin >> m >> n;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << minCostPath_mem(arr, m, n) << endl;
    cout << minCostPath(arr, m, n) << endl;
    cout << minCostPath_DP(arr, m, n) << endl;
}