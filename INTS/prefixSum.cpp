#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        int c=0;
        
        for(int c1=0;c1<n;c1++){
            for(int c2=c1;c2<n;c2++){
                map<int,int> mp;
                mp[0]++;                    //sum-target=0 hoha tbhi we added m[0]=1
                int sum=0;
                for(int i=0;i<m;i++){
                    sum+=mat[i][c2] - (c1>0 ? mat[i][c1-1] : 0);
                    c+= mp[sum-target];     // this checks sum==target
                    mp[sum]++;
                }
                
            }
        }
        return c;
    }
};

int main(){
    return 0;
}