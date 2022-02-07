#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int n, int x)
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step = step + sqrt(n);

        if (prev >= x)
        {
            return -1;
        }
    }
    while (arr[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
        {
            return -1;
        }
    }
    if (arr[prev] == x)
    {
        return prev;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, x, i;

    int arr[] = {2, 4, 7, 9, 11, 40, 69, 77,79,85,96,101,109,118,136,169,183};
    n = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Element be searched : " << endl;
    cin >> x;

    int Result = jumpSearch(arr, n, x);

    if (Result == -1)
    {
        cout << "Element not Found.";
    }
    else
    {
        cout << "Element Found! at " << Result + 1 << " position.";
    }
}