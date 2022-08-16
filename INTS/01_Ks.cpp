#include <bits/stdc++.h>
using namespace std;

int dp[51][51];

int ks(int W,vector<int>& wt,vector<int>& val,int i){
    
    if(i<0){
        return 0;
    }
    if(dp[W][i]!=-1){
        return dp[W][i];
    }
    int t=-1,nt=-1;

    if(W>=wt[i]){
        t=val[i]+ks(W-wt[i],wt,val,i-1);
    }
    nt=ks(W,wt,val,i-1);

    return dp[W][i] = max(t,nt);
}

int main()
{
	vector<int> val = { 60, 100, 120 };
	vector<int> wt = { 10, 20, 30 };

    memset(dp,-1,sizeof(dp));

	int W = 50;
	int n = val.size();
	cout << ks(W, wt, val, n-1);
	return 0;
}

