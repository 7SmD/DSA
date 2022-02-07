#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{

    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < subArrayOne; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int indexOfsubArrayOne = 0, indexOfsubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfsubArrayOne < subArrayOne && indexOfsubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfsubArrayOne] <= rightArray[indexOfsubArrayTwo])
        {
            arr[indexOfMergedArray] = leftArray[indexOfsubArrayOne];
            indexOfsubArrayOne++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArray[indexOfsubArrayTwo];
            indexOfsubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfsubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfsubArrayOne];
        indexOfsubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfsubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfsubArrayTwo];
        indexOfsubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int arr[], int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = begin + (begin - end) / 2;

    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, begin, mid, end);
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
    mergeSort(arr, 0, n - 1);
    cout << "Array after Sorting: ";
    display(arr, n);
}