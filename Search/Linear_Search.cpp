#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            return i;
        }
    }
    return -1;
    
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, x, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array : ";
    display(arr, n);
    cout << "Enter element to be Searched:" << endl;
    cin >> x;
    int found = search(arr, n, x);
    if (found == -1)
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Element Found at index " << found;
    }
}