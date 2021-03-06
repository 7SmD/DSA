#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int *input, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int key = input[i];
        if (m.count(key) == 0)
        {
            m[key] = 1;
        }
        else
        {
            m[key]++;
        }
    }

    int max = m[input[0]];
    int ans = input[0];
    int j = 1;

    while (j < n)
    {
        if (m[input[j]] > max)
        {
            max = m[input[j]];
            ans = input[j];
        }
        j++;
    }
    return ans;
}

int main()
{
    int n;
    int input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int maxKey = highestFrequency(input, n);
    cout << maxKey;
    return 0;
}
