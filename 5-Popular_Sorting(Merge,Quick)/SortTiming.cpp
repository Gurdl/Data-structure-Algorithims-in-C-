// Name:Gurdev singh
// id:100376466
#include <iostream>
#include "time.h"
using namespace std;
#include "Methods.cpp"
int main()
{
    // Start creating random size arryas:
    srand(time(0));
    //------Array size is 1000------------
    int n = 2000;
    int m = 1000;
    double start, end;
    int first = 1;
    int last = 999;
    cout << "The size of array wil be n=" << n << endl;
    // ------TRY m=100
    //--------------------COCKTAIL SORT-----------------------------
    start = clock();
    for (int i = 0; i < m; i++)
    {
        int Arr[n];
        // again input the data into array
        for (int i = 0; i < n; i++)
        {
            int random = rand() % (last + 1 - first) + first;
            Arr[i] = random;
        }
        cocktailSort(Arr, n);
    }
    end = clock();
    cout << "\n----------------Cocktail SORT-----------------\nTime to sort:  " << (end - start) / m << " When n is " << n << endl;

    //-----------------------Quick Sort-----------------------------
    start = clock();
    for (int i = 0; i < m; i++)
    {
        int Arr[n];
        // again input the data into array
        for (int i = 0; i < n; i++)
        {
            int random = rand() % (last + 1 - first) + first;
            Arr[i] = random;
        }

        quickSort(Arr, n);
    }
    end = clock();
    cout << "\n----------------Quick SORT-----------------\nTime to sort:  " << (end - start) / m << " When n is " << n << endl;
    //--------------------------------MERGE SORT------------------------------------
    int W[n];
    start = clock();
    for (int i = 0; i < m; i++)
    {
        int Arr[n];
        // again input the data into array
        for (int i = 0; i < n; i++)
        {
            int random = rand() % (last + 1 - first) + first;
            Arr[i] = random;
        }

        mergeSort(Arr, W, n);
    }
    end = clock();
    cout << "\n----------------Merge SORT-----------------\nTime to sort:  " << (end - start) / m << " When n is " << n << endl;

    return 0;
}
