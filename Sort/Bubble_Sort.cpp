
#include <iostream>
using namespace std;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sort(int a[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    display(arr, n);
    sort(arr, n - 1);
    cout << "Array after Sorting: ";
    display(arr, n);
}