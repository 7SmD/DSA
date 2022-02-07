#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int kSmallest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (pq.top() < input[i])
        {
            pq.pop();
            pq.push(input[i]);
        }
    }
    return pq.top();
}

int main()
{
    int input[] = {9, 4, 8, 7, 11, 3};
    int k = 2;
    cout << kSmallest(input, 6, k);
}
