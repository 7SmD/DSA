#include <iostream>
using namespace std;
#include <vector>
#include <queue>

void kLargest(int input[], int n, int k)
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
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    int input[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int k = 4;
    kLargest(input, 13, k);
}
