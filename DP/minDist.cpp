#include <iostream>
using namespace std;
#include <cmath>
#include <string>
/*
//recursive
int editDistance(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }
    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        //insert
        int x = editDistance(s.substr(1), t) + 1;
        //delete
        int y = editDistance(s, t.substr(1)) + 1;
        //replace
        int z = editDistance(s.substr(1), t.substr(1)) + 1;
        return min(x, min(y, z));
    }
}

//Memoziation
int editDistance_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }
    int ans;

    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    if (s[0] == t[0])
    {
        return editDistance_mem(s.substr(1), t.substr(1), output);
    }
    else
    {
        //insert
        int x = editDistance_mem(s.substr(1), t, output) + 1;
        //delete
        int y = editDistance_mem(s, t.substr(1), output) + 1;
        //replace
        int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;
        ans = min(x, min(y, z));
    }
    output[m][n] = ans;
    return ans;
}

int editDistance_mem_helper(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, output);
}


int editDistance_mem_helper(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, output);
}
*/

//Dp
int editDistance_DP(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    output[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        output[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = 1 + output[i - 1][j];
                int b = 1 + output[i - 1][j - 1];
                int c = 1 + output[i][j - 1];
                output[i][j] = min(a, min(b, c));
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    //cout << editDistance(s, t) << endl;
    //cout << editDistance_mem_helper(s, t) << endl;
    cout << editDistance_DP(s, t) << endl;
}