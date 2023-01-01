//Name:Gurdev singh
//id:100376466
#include <iostream>
using namespace std;
void cocktailSort(int A[], int n);
void printArray(int Arr[], int n);
void mergeArray(int A[], int W[], int startIndex, int endIndex, int midIndex);
void mergeSort(int A[], int W[], int n);
void mergeSort(int A[], int W[], int startIndex, int endIndex);
void quickSort(int Arr[], int n);
void quickSort(int Arr[], int startIndex, int endIndex);
int partioned(int Arr[], int startIndex, int endIndex);
void printArray(int Arr[], int n);
// This method is used to print any size of an array:
// The size of an array is n:
void printArray(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " , ";
        if (i % 7 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
//--------------------------Cocktail Sort---------------------------------------
// This function will sort the given array
// Precondition:
//  array size must be greater than 0;
// PostCondition:
// Array will be sorted:
//  Time complexity: O(n^2);
void cocktailSort(int A[], int n)
{
    for (int i = 0; i <= n / 2; i++)
    {
        // Forward loop to place the largest element on right side:
        for (int j = i; j < n - i - 1; j++)
        {
            // if current elemnt is greater than the next element,Swap
            if (A[j] > A[j + 1])
            {
                // swap:
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        // backward loop to place the smallest elemnt on left side:
        for (int k = n - 2 - i; k > i; k--)
        {
            // if the current elemnt is smaller than previous element ,swap
            if (A[k] < A[k - 1])
            {
                // swap
                int temp = A[k];
                A[k] = A[k - 1];
                A[k - 1] = temp;
            }
        }
    }
}
//----------------------Merge Sort-------------------------------
// This function follows merge sort algorithom and it will sort an array:
// precondition:
// n >0
// postCondition:
// returned Array will be sorted
//  Complexity: n(Logn)
void mergeSort(int A[], int W[], int n)
{
    int startIndex = 0;
    int endIndex = n - 1;
    mergeSort(A, W, startIndex, endIndex);
}
void mergeSort(int A[], int W[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }
    int midIndex = (startIndex + endIndex) / 2;
    mergeSort(A, W, startIndex, midIndex);
    mergeSort(A, W, midIndex + 1, endIndex);
    mergeArray(A, W, startIndex, endIndex, midIndex);
}
void mergeArray(int A[], int W[], int startIndex, int endIndex, int midIndex)
{
    int n = endIndex - startIndex + 1;
    W[n];
    int index1 = startIndex;
    int index2 = midIndex + 1;
    int x = 0;
    while (index1 <= midIndex && index2 <= endIndex)
    {
        if (A[index1] < A[index2])
        {
            W[x] = A[index1];
            x++;
            index1++;
        }
        else
        {
            W[x] = A[index2];
            x++;
            index2++;
        }
    }
    while (index1 <= midIndex)
    {
        W[x] = A[index1];
        x++;
        index1++;
    }
    while (index2 <= endIndex)
    {
        W[x] = A[index2];
        x++;
        index2++;
    }
    // Now pass all elements of W into A:
    for (int i = 0, j = startIndex; i < n; i++, j++)
    {
        A[j] = W[i];
    }
}
//--------------------------Quick Sort------------------------------
// This function will sort given array of size n
// PreCondition ,n>0
// PostCondition:
// The array will be sorted:
void quickSort(int Arr[], int n)
{
    int startIndex = 0;
    int endIndex = n - 1;
    quickSort(Arr, startIndex, endIndex);
}
void quickSort(int Arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int pivotIndex = partioned(Arr, startIndex, endIndex);
        quickSort(Arr, startIndex, pivotIndex - 1);
        quickSort(Arr, pivotIndex + 1, endIndex);
    }
}
int partioned(int Arr[], int startIndex, int endIndex)
{
    int pivotIndex = endIndex;
    int i = startIndex - 1;
    for (int j = startIndex; j < pivotIndex; j++)
    {
        // swapping with larger and smaller element:
        if (Arr[j] < Arr[pivotIndex])
        {
            i++;
            int temp = Arr[j];
            Arr[j] = Arr[i];
            Arr[i] = temp;
        }
    }
    i++;
    int temp = Arr[i];
    Arr[i] = Arr[endIndex];
    Arr[endIndex] = temp;
    return i;
}