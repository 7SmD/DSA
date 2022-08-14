
#include <bits/stdc++.h>
using namespace std;

stack<int> s;

vector<int> f(vector<int> &arr, int n)
{
    vector<int> v;
    int i = 0;
    while (i <= n - 1)
    {
        while (s.size() > 0 && arr[i] <= s.top())
        {
            s.pop();
        }
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (arr[i] > s.top())
        {
            v.push_back(s.top());
        }

        s.push(arr[i]);
        i++;
    }

    return v;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();

    vector<int> ans = f(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    cout << endl;

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}