#include <iostream>
using namespace std;

#include <stack>
bool checkRedundantBrackets(string input)
{

    stack<char> s;
    int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] == ')')
        {
            int count = 0;
            while (s.top() != '(')
            {
                count++;
                s.pop();
            }
            s.pop();
            if (count == 0 || count == 1)
            {
                return true;
            }
            i++;
        }
        else
        {
            s.push(input[i]);
            i++;
        }
    }
    return false;
}
int main(){
    string str;
    cin>>str;
    int check=checkRedundantBrackets(str);
    cout<<endl<<check;

}