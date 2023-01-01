// Name:Gurdev singh
// id:100376466
#include <iostream>
#include <time.h>
using namespace std;
//Thus function iterate in forward way and place the largest element on the right side:
void forwardIteration(int Arr[], int startIndex, int endIndex)
{
    for (int j = startIndex; j < endIndex; j++)
    {
        // if previous element is bigger swapp:
        if (Arr[j] > Arr[j + 1])
        {
            int temp = Arr[j];
            Arr[j] = Arr[j + 1];
            Arr[j + 1] = temp;
        }
    }
}
// This function will iterate in backward way and place the smallest element on its left place:
void backwardIteration(int Arr[], int backStartIndex, int frontEndIndex)
{
    for (int j = backStartIndex; j > frontEndIndex; j--)
    {
        // if current element is smaller than initial, swapp
        // keep smaller elemet at starting:
        if (Arr[j] < Arr[j - 1])
        {

            int temp = Arr[j];
            Arr[j] = Arr[j - 1];
            Arr[j - 1] = temp;
        }
    }
}
// This function will sort the given array of size n:
// precondition:
// The array size must be greater than 0;
// postCondition:
// The given array will be sorted:
void sort(int A[], int n)
{
    // Use this to iterate all the array:
    for (int i = 0; i < n / 2; i++)
    {
        int startForward = i;
        int endForward = n - 1 - i;
        forwardIteration(A, startForward, endForward);
        int backwardStart = n - 2 - i;
        int backwardEnd = i;
        backwardIteration(A, backwardStart, backwardEnd);
    }
}
int main()
{
    int size = 17;
    const int perLine = 5;
    int first = 0;
    int last = 999;
    int Arr[size];
    srand(time(0)); // A seed for random values
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
    sort(Arr, size);
    cout << endl
         << "\nAfter sorting array we get" << endl;
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