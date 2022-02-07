#include <iostream>
using namespace std;
#include <cmath>

int stairs(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}

int main()
{
    cout << stairs(4);
}