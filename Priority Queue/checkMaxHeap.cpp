#include <iostream>
using namespace std;
#include <vector>
#include <queue>

bool checkMaxHeap(int input[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        if (input[2 * i + 1] > input[i])
        {
            return false;
        }
        if (2 * i + 2 < n && input[2 * i + 2] > input[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int input[] = {42, 20, 18, 6, 14, 11, 9, 4};
    cout << checkMaxHeap(input, 8);
}
