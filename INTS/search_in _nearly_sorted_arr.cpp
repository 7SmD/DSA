#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int x){

    while(l<=r){
        int m=l+(r-l)/2;

        if(arr[m]==x){
            return m;
        }
        else if(m-1>=l && arr[m-1]==x){
            return m-1;
        }
        else if(m+1<=r &&arr[m+1]==x){
            return m+1;
        }
        else if(arr[m]>x){
            r=m-2;
        }
        else if(arr[m]<x){
            l=m+2;
        }

    }

    return -1;
}

int main()
{
    vector<int> arr = {3, 2, 10, 4, 40};
    int n = arr.size();
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);
    cout<<result;
    return 0;
}
