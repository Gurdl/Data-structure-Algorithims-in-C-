// Name: Gurdev singh
// Student Number:100376466
// CPSC 1160 Assignment #3
#include <iostream>
#include <string>
using namespace std;
using std::string;
// precondition: n > 0
// CPSC 1160: if no second argument is passed, the default argument
// for the stream is std::cout
void writeBackwardForward(unsigned int n, std::ostream &out = std::cout);
void backwardPrinterHelper(string str, std::ostream &out = std::cout); // Helper functon for writeBackwardForward()
void forwardPrinterHelper(string str, std::ostream &out = std::cout);  // Helper function for writeBackwardForward()
// precondition:
//   1 <= n <= declared size of the array A
bool smaller(int x, const int A[], int n);

// precondition:
//   1 <= n <= declared size of the array A
int maximum(const int A[], int n);

bool isStrictlyDescending(const int A[], int n);

// precondition:
//   1 <= n <= declared size of the array A
void swapPairsLeftToRight(int A[], int n);

short goesFirst(string strA, string strB, int &i, int n);
short goesFirst(const string &strA, const string &strB);//Helper function is recursive too

// BONUS
// precondition:
//   1 <= n <= declared size of the array A
int minPosNum(const int A[], int n);
int minValue(int A[], int n, int &f);//Helper ,recursive
//-----------------------------------------FUNCTIONS----------------------------------

// Question:1)-------------------------------------------------------------------------
//This is use to print backward
//--Helper Function for writeBcakwardfarward() function
void backwardPrinterHelper(string str, std::ostream &out)
{
   // base case
   if (str.length() == 0)
   {
      return;
   }
   backwardPrinterHelper(str.substr(1), out);
   out << str[0];
}
//--Helper Function for to print forward
void forwardPrinterHelper(string str, std::ostream &out)
{
   if (str.length() == 0)
   {
      return;
   }
   out << str[0];
   forwardPrinterHelper(str.substr(1), out);
}
// This function will print the number in backward way and forward way using recursion
//  precondition: n > 0
void writeBackwardForward(unsigned int n, std::ostream &out)
{
   string str = to_string(n);
   backwardPrinterHelper(str, out);
   out << endl;
   forwardPrinterHelper(str, out);
}

// Question:2)------------------------------------------------------------------------------
// This function will determine if the elements in array A
// are smaller than  X ,if n is the given size of an array
// precondition:
//   1 <= n <= declared size of the array A
bool smaller(int x, const int A[], int n)
{
   // base case
   if (n == 0)
   {
      return true;
   }
   if (A[0] >= x)
   {
      return false;
   }
   return smaller(x, A + 1, n - 1);
}

//QUESTION:3)------------------------------------------------------------------------------
// Find the maximum value in the array.
// precondition:
//   1 <= n <= declared size of the array A
// postcondition:
//   return the maximum value in the first n elements of A
int maximum(const int A[], int n)
{
   // base case:
   if (n == 1)
   {
      return A[0];
   }
   int num = A[0];
   int restArray = maximum(A + 1, n - 1);
   if (num > restArray)
   {
      return num;
   }
   else
   {
      return restArray;
   }
}

//Question:4---------------------------------------------------------------------
// This function will check if the given array is in descending order or not.
// Precondition:
//  n>0 and A must have some elements
bool isStrictlyDescending(const int A[], int n)
{
   if (n == 1)
   {
      return true;
   }
   bool restArray = isStrictlyDescending(A + 1, n - 1);
   return (A[0] > A[1] && restArray);
}
//Question:5----------------------------------------------------------------------
//This function will swap the left value with right value like First with second
// third with fourth and so on..
// precondition:
//   1 <= n <= declared size of the array A
void swapPairsLeftToRight(int A[], int n)
{
   if (n == 1 || n == 0)
   {
      return;
   }
   int temp = A[0];
   A[0] = A[1];
   A[1] = temp;
   swapPairsLeftToRight(A + 2, n - 2);
}

//Question:6---------------------------------------------------------------------
//This function will determine if strA goes before strB in a dictionary.
//if strA is before strB in dictionary ,it will return 1,otherwise
//it will return -1.
//if both string are same it will return 0.
//Precodition:
//The string may not contain letters.
short goesFirst(const string &strA, const string &strB)
{
   int i = 0;
   int nA = strA.length();
   int nB = strB.length();
   int n = nA;
   if (nB > nA)
   {
      n = nB;
   }
   short value = goesFirst(strA, strB, i, n);//Helper function
   return value;
}
//Helper Function is recursive too..
short goesFirst(string strA, string strB, int &i, int n)
{
   // base case:;
   // When both string are empty:
   if (i == n)
   {
      return 0;
   }
   // first string is empty:
   int nA=strA.length();
   if (i > nA)
   {
      return 1;
   }
   // second string is empty
   int nB=strB.length();
   if (i > nB)
   {
      return -1;
   }
   char A = tolower(strA[i]);
   char B = tolower(strB[i]);
   if (A < B)
   {
      return 1;
   }
   else if (A > B)
   {
      return -1;
   }
   i = i + 1;
   short temp = goesFirst(strA, strB, i, n);
   return temp;
}

//BONUS QUESTION ----------------------------------------------------------
//This function is used to get the minimum positive value in an given array.
//if the there is no positive value it will return 0
// precondition:
//   1 <= n
int minPosNum(int A[], int n)
{
   if (n == 0)
   {
      return 0;
   }
   // if ,we et first postive value
   if (A[n - 1] > 0)
   {
      int f = A[n - 1];
      return minValue(A, n, f);
   }
   else
   {
       minPosNum(A, n - 1);
   }
}
//This is helper function which is recursive too.
int minValue(int A[], int n, int &f)
{
   if (n == 0)
   {
      return 0;
   }
   if (A[n - 1] > 0)
   {
      if (f > A[n - 1])
      {
         f = A[n - 1];
      }
   }
   else
   {
        minValue(A, n - 1, f);
   }
         minValue(A, n - 1, f);
   return f;
}
