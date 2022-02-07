#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    if (input.size() == 0 || input.size() == 1)
    {
        return;
    }
    int x = input.top();
    input.pop();
    reverseStack(input, extra);
    while (!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    while (!extra.empty())
    {
        input.push(extra.top());
        extra.pop();
    }
}

int main()
{
    stack<int> s1, s2;
    int n, element;
    cout << "No. of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> element;

        s1.push(element);
    }
    cout << endl;
    reverseStack(s1, s2);
    cout << "Reversed Stack : ";
    for (int i = 0; i < n; i++)
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}