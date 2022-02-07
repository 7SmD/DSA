#include <iostream>

#include <stack>

using namespace std;

bool balancedBracket(string x, int len)
{
    stack<char> s;

    for (int i = 0; i < len; i++)
    {
        if (x[i] == '{' || x[i] == '(' || x[i] == '[')
        {
            s.push(x[i]);
        }
        else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            if (s.empty())
            {
                return false;
            }
            char ch = s.top();
            s.pop();
            if (x[i] == ')' && ch == '(')
            {
                continue;
            }
            else if (x[i] == ']' && ch == '[')
            {
                continue;
            }
            else if (x[i] == '}' && ch == '{')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        false;
    }
}

int main()
{
    string x;
    cin >> x;
    int len = x.length();
    //cout<<"Length : "<<len<<endl;
    cout << balancedBracket(x, len);
}