int mod=(int)(1e9+7);
int f(int i,int sum,vector<int> &arr,vector<vector<int>>& dp){
//     if(sum==0){
//         return 1;
//     }
    if(i==0){
        if(sum==0 && arr[0]==0) return 2;
        if(sum==0 || sum==arr[0]) return 1;
        return 0;
    }
    
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    
    int t=0;
    int nt=f(i-1,sum,arr,dp);
    
    if(sum>=arr[i]){
        t=f(i-1,sum-arr[i],arr,dp);
    }
    
    return dp[i][sum]=(t+nt)%mod;
}

int countPartitions(int n, int d, vector<int> &arr,int sum) {
    // int sum=0;
    // for(auto &it:arr){
    //     sum+=it;
    // }
    // if(sum-d<0 || (sum-d)%2){
    //     return false;
    // }
    // int x=(sum-d)/2;
    vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
    return f(n-1,sum,arr,dp);
}



#include<bits/stdc++.h>
using namespace std;
