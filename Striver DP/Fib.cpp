#include<bits/stdc++.h>
using namespace std;

int jump(int n){

    vector<int> dp(n+1,-1);

    dp[0]=0;
    dp[1]=1;

    for (int i = 2; i <= n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    return dp[n];

}


int main(){
    //0 1 1 2 3 5 8 13 21   // starting index 0
    cout<<jump(8);
}