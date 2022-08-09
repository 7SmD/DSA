#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    queue<int> q;
    vector<int> ans;
    int i = 0,j = 0;
    
    while(j<n){
        if(arr[j]<0)
            q.push(arr[j]);

        if(j-i+1 < k){
            j++;
        }

        else{
            if(q.empty()) ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(q.front() == arr[i])
                    q.pop();
            }
            i++;
            j++;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}
