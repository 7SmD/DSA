#include<bits/stdc++.h>
using namespace std;

int solve(int ind,int arr[],vector<int>& dp){
    if(ind==0){
        return arr[ind];
    }
    if(ind<0){
        return 0;
    }

    if(dp[ind]!=-1){
        return dp[ind];
    }

    //pick
    int p=arr[ind]+solve(ind-2,arr,dp);
    int np=0+solve(ind-1,arr,dp);

    return dp[ind]=max(p,np);

    
}


int main(){
    int arr[]={2,9,1,4,9};
    int n=5;
    
    vector<int> dp(n,-1);
    cout<<solve(n-1,arr,dp);
}