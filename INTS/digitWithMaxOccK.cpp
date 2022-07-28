#include<bits/stdc++.h>
using namespace std;

int maxi=0;
int ind=-1;
int f(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int c=0;
        while(temp>0){
            int x=temp%10;
            if(x==k){
                c++;
            }
            temp/=10;
        }
        if(maxi<c){
            maxi=c;
            ind=i;
        }
        //maxi=max(maxi,c);
    }
    return ind;
}

int main()
{
    int K = 7;
 
    // Given array
    int arr[] = { 3, 77, 343, 456 };
 
    // Size of array
    int N = sizeof(arr) / sizeof(arr[0]);
 
    
    int ind=f(arr,N,K);
    if(ind!=-1){
        cout<<arr[ind];
    }
    else{
        cout<<-1;
    }
    return 0;
}