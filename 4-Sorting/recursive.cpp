#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void sortR_ForwardIteration(int Arr[], int startIndex, int endIndex)
{
    // base condition:
    if (startIndex == endIndex)
    {
        return;
    }

    int j = startIndex;
    // if previous element is bigger swapp:
    if (Arr[j] > Arr[j + 1])
    {
        int temp = Arr[j];
        Arr[j] = Arr[j + 1];
        Arr[j + 1] = temp;
    }
    sortR_ForwardIteration(Arr, startIndex + 1, endIndex);
}
// This function will iterate in backward way and place the smallest element on its right place:
void sortR_BackwardIteration(int Arr[], int backStartIndex, int frontEndIndex)
{
    // BASE condition:
    if (backStartIndex == frontEndIndex)
    {
        return;
    }

    int j = backStartIndex;
    // if previous element is smaller than current, swapp:
    if (Arr[j] < Arr[j - 1])
    {
        int temp = Arr[j];
        Arr[j] = Arr[j - 1];
        Arr[j - 1] = temp;
    }
    sortR_BackwardIteration(Arr, backStartIndex - 1, frontEndIndex);
}
// This function will sort the given array  revursively of size n:
// precondition:
// The array size must be greater than 0;
// postCondition:
// The given array will be sorted:
void sortR(int A[], int n)
{
    // base case:
    if (n == 0)
    {
        return;
    }
    int startForward = 0;
    int endForward = n;
    sortR_ForwardIteration(A, startForward, endForward); // This function is recursive :
    // backwardInteration:
    int backwardStart = n - 1;
    int backwardEnd = 0;
    sortR_BackwardIteration(A, backwardStart, backwardEnd); // This function is recursive too:

    // recursive function too:
    sortR(A + 1, n - 1);
}
int main()
{
    int size = 17;
    const int perLine = 5;
    int first = 0;
    int last = 999;
    int Arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        // add random values:
        Arr[i] = rand() % (last + 1 - first) + first;
        if (i % perLine == 0)
        {
            cout << endl;
        }
        cout << Arr[i] << " , ";
    }
    sortR(Arr, size);
    cout << endl
         << "After sorting array we get" << endl;
    for (int i = 0; i < size; i++)
    {
        if (i % perLine == 0)
        {
            cout << endl;
        }
        cout << Arr[i] << " , ";
    }
    return 0;
}