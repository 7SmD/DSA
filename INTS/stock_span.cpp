
#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;

vector<pair<int, int>> f(vector<int> &arr, int n)
{
    vector<pair<int, int>> v;
    int i = 0;
    while (i <= n - 1)
    {
        while (s.size() > 0 && arr[i] >= s.top().first)
        {
            s.pop();
        }
        if (s.empty())
        {
            v.push_back({-1, -1});
        }
        else if (arr[i] < s.top().first)
        {
            v.push_back({s.top().first, s.top().second});
        }

        s.push({arr[i], i});
        i++;
    }

    return v;
}

int main()
{
    vector<int> arr = {100,80,60,70,60,75,85};
    int n = arr.size();

    vector<pair<int, int>> ans = f(arr, n);
    for (auto i : arr)
    {
        cout << i << "          ";
    }

    cout << endl;

    for (auto i : ans)
    {
        cout << i.first << " " << i.second << "     ";
    }

    vector<int> v;

    cout << endl
         << "Checking max len among : ";

    for (int i = 0; i < ans.size(); i++)
    {
        ans[i].second = i - ans[i].second;
    }

    int maxi = 0;

    for (auto i : ans)
    {
        maxi = max(maxi, i.second);
        cout << i.second << " ";
    }
    cout << endl;
    cout << maxi;
    return 0;
}