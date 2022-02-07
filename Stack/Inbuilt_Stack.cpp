#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int a = s.top();
    s.pop();
    int b = s.top();

    cout << a << " " << b << " " << s.size() << " " << s.empty();
}