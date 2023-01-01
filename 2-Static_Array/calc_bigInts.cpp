// Name: Gurdev singh                       Id:100376466
// CPSC 1160 Assignment #2
/*
g++ -pedantic -Wall -Wextra  -std=c++17 calc_bigInts.cpp -o calc_bigInts
*/
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// it is terrible programming style to #include an implementation cpp file    //
//      do not do this in general, only at the beginning of the course        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
#include "bigInts.cpp"
#include <iostream>
#include <string>
using namespace std;
// size of the arrays
// CPSC 1160 fill in properly
const int MAX_NUM_DIGITS = 72;
// ask the user
void printOppsiteArray(int array[], int nArray);
int main()
{
    bool repeat = true;
    int cont = 0;
    string firstNum, secondNum;
    int base = 0;
    do
    {
        cout << "Enter the base number";
        cin >> base;
        while (base > 16 || base < 0)
        {
            cout << "Enter the base number less than or equal to 16";
            cin >> base;
        }
        cout << "Enter the first  Number\n";
        cin >> firstNum;
        //----Take Valid user Inputs----
        // Check if the given string contain only Number values
        while (!isNumber(firstNum) || firstNum.length() > MAX_NUM_DIGITS)
        {
            cout << "The Number must contain only positive  int values\n";
            cin >> firstNum;
        }
        cout << "Enter the Second Number\n";
        cin >> secondNum;
        // Check if the given string contain only Number values
        while (!isNumber(secondNum) || secondNum.length() > MAX_NUM_DIGITS)
        {
            cout << "The Number must contain only positive  int values\n";
            cin >> secondNum;
        }
        // Decalare two arrays:
        int A[firstNum.length()] = {0};
        int B[secondNum.length()] = {0};
        int C[MAX_NUM_DIGITS] = {0};
        char finalC[firstNum.length()]={'A'};
        int nA = 0;
        int nB = 0;
        int nC = 0;
        // covertTwo String into arrays:
        bool firstArrayConverted = fromStringToArray(firstNum, A, MAX_NUM_DIGITS, nA, base);
        bool secondArrayCoverted = fromStringToArray(secondNum, B, MAX_NUM_DIGITS, nB, base);
        bool sum = add(A, nA, B, nB, C, nC, base);
        if (sum)
        {
            // Space on Left side:
                int tabSpaceB = nC - nB, tabSpaceA = nC - nA;
            if (base <= 10)
            {
                
                // first Number in array:
                cout << "ANS:" << endl;
                coutBigInt(A, nA, 1, tabSpaceA);
                cout << "+" << endl;
                coutBigInt(B, nB, 1, tabSpaceB);
                cout << "___________________________" << endl;
                coutBigInt(C, nC, 1, 0);
            }
            else
            {
                printBaseArray( A,  nA,  finalC,  1, tabSpaceA  );
                cout << "+" << endl;
                printBaseArray( B,  nB,  finalC,  1,  tabSpaceB );
                cout << "___________________________" << endl;
                printBaseArray( C,  nC,  finalC,  1,  0);

            }
            cout << "To continue press 1\n";
            cin >> cont;
            if (cont != 1)
            {
                repeat = false;
                cout << "\n--Program Ends--";
            }
        }
        else
        {
            cout << "Your sum of two number exceeds than the size of array";
        }
    } while (repeat);
    return 0;
}
