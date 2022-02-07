#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.size() <= 1)
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    int n, element;
    cout << "No. of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> element;

        q.push(element);
    }
    cout << endl;
    reverseQueue(q);
    cout << "Reversed queue : ";
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
}