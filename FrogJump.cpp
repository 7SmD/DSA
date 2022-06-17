#include <bits/stdc++.h>
using namespace std;

int jump(int n,int arr[],vector<int>& dp)      //memoization TOP -> DOWN
{
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int l=jump(n-1,arr,dp)+abs(arr[n]-arr[n-1]);
    int r=INT8_MAX;
    
    if(n>=2){
        r=jump(n-2,arr,dp)+abs(arr[n]-arr[n-2]);
    }

    return dp[n]=min(l,r);
    
}

int main()
{
    int arr[] = {30, 10, 60, 10, 60, 50};
    int n=6;

    vector<int> dp(n+1,-1);

    cout << jump(n-1,arr,dp);
}