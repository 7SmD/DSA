#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

char *uniqueChar(char *str)
{
    int len = strlen(str);
    if (len == 0)
    {
        char *ans = new char[1];
        ans[0] = '\0';
        return ans;
    }

    char *ans = new char[len + 1];
    unordered_map<char, bool> uc;
    int i = 0;

    for (int currInd = 0; currInd < len; currInd++)
    {
        char currChar = str[currInd];
        if (uc.count(currChar) == 0)
        {
            uc[currChar] = true;
            ans[i++] = currChar;
        }
    }
    ans[i] = '\0';
    return ans;
}

int main()
{
    char inp[100];
    cin >> inp;
    cout << uniqueChar(inp);
}