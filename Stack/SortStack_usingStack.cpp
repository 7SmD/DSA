// C++ program to sort a stack using an
// auxiliary stack.
#include <bits/stdc++.h>
using namespace std;

// This function return the sorted stack
stack<int> sortStack(stack<int> &s1)
{
	stack<int> f;

    while(!s1.empty()){

        int t=s1.top();
        s1.pop();

        while(!f.empty() && f.top()<t){
            s1.push(f.top());
            f.pop();

        }
        f.push(t);
    }
    return f;
}

int main()
{
	stack<int> input;
	input.push(3);
	input.push(3);
	input.push(31);
	input.push(9);
	input.push(92);
	input.push(23);

	stack<int> tmpStack = sortStack(input);
	cout << "Sorted numbers are:\n";

	while (!tmpStack.empty())
	{
		cout << tmpStack.top()<< " ";
		tmpStack.pop();
	}
}
