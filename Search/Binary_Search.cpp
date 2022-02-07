#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
            
        int m = l + (h - l)/ 2;

        if (arr[m] == x)
        {
            return m;
        }
        if(arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n, x, i;
    
    int arr[] = {2, 4, 7, 9, 11, 40, 69, 77};
    n = sizeof(arr) / sizeof(arr[0]);
    
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout << "Element be searched : " << endl;
    cin >> x;


    int Result = binarySearch(arr, 0, n - 1, x);

    if (Result == -1)
    {
        cout << "Element not Found.";
    }
    else
    {
        cout << "Element Found! at " << Result + 1 << " position.";
    }
}