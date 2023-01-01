// Name: Gurdev singh                            id:100376466
// CPSC 1160 Assignment #2
#include <iostream>
#include <string>
using namespace std;
// for output
const char BLANK = ' ';
// Check if the given string is a number or not:
// PreCondition:
// Only A string must be passed
// PostCondition:
// if a string is a number ,True will be returned
bool isNumber(string str)
{
   for (int i = 0; i < str.length(); i++)
   {
      if ((isdigit(str[i])) || str[i] != 'A' || str[i] != 'B' || str[i] != 'C' || str[i] != 'D' ||
          str[i] != 'E' || str[i] != 'F')
      {
         return true;
      }
   }
   return false;
}
// given a ch, return its numerical equivalent if it corresponds to a digit
// e.g. for '9' return 9
// postcondition:
//    return -1 if the ch does not correspond to a digit base 10
//    otherwise return the numeric value of ch e.g. 0, 1, 2
int number(char ch)
{
   int num = ch - 48;
   return num;
}
// convert the digit x (base 10 unless you are doing the BONUS)
// into a character
// precondition:
//    0 <= x < MAXIMUM_BASE which is 16
// postcondition:
//    0 -> '0'   .... 10 ->'A'  11 -> 'B' .... 15 -> 'F'
char character(int x)
{
   switch (x)
   {
   case 10:
      return 'A';
      break;
   case 11:
      return 'B';
      break;
   case 12:
      return 'C';
      break;
   case 13:
      return 'D';
      break;
   case 14:
      return 'E';
      break;
   case 15:
      return 'F';
      break;
   default:
      char ans = (char)(48 + x);
      return ans;
      break;
   }
}
// add the first nA digits of A with the first nB digits of B
// to produce nC digits in C
// if the result of A plus B would have required more than nC digits in C
// return false meaning that the sum is not possible
// otherwise return true with the sum in the nC digits of C
// CPSC 1160: 0 is a SPECIAL CASE, choose your representation of 0
// precondition:
//     nA <= declared size of A
//     0 <= A[i] < 10 for 0 <= i < nA
//     the least significant digits of the number to add are at A[0], A[1], ...
//     nB <= declared size of B
//     0 <= B[i] < 10 for 0 <= i < nB
//     the least significant digits of the number to add are at B[0], B[1], ...
//     nC == declared size of C (on input nC has the declared size of C)
// postcondition:
//     C is the result of A + B and C has nC (significant) digits
//     0 <= C[i] < 10 for 0 <= i < nC
//     the least significant digits of the number to add are at C[0], C[1], ...
//     return true if A + B is successful, false otherwise
//                  nC has the number of significant digits of C
//     return false if there was no room in C for A + B
bool add(const int A[], int nA, const int B[], int nB, int C[], int &nC)
{
   int carry = 0, sum = 0, value = 0;
   nC = 0;
   int greatestNumber = nA;
   if (nB > nA)
   {
      greatestNumber = nB;
   }
   for (int i = 0; i < nA || i < nB; i++)
   {
      // if elements in array A finishes ,than add only B
      if (i < nA && i < nB)
      {
         sum = A[i] + B[i] + carry;
         carry = 0;
      }
      else if (i >= nA)
      {
         sum = B[i] + carry;
         carry = 0;
      }
      else if (i >= nB)
      {
         sum = A[i] + carry;
         carry = 0;
      }
      if (sum >= 10)
      {
         value = sum % 10;
         C[i] = value;
         nC++;
         carry = sum / 10;
         if (carry > 0 && (i == greatestNumber - 1))
         {
            C[i + 1] = carry;
            nC++;
         }
      }
      else
      {
         value = sum;
         C[i] = value;
         nC++;
      }
   }
   if (nC > 72)
   {
      return false;
   }
   else
   {
      return true;
   }
}
// from str (with any type of characters), convert each character in the string
// into a digit (using the helper function number)
// store all the digits into an array A in reverse order from the string
// without leading zeros
// CPSC 1160: 0 is a SPECIAL CASE, choose your representation of 0
// precondition:
//     A has been declared to have at least size elements
// postcondition:
//    return false if the number of characters of str is greater than size
//    return false if a character in str does not correspond to a number
//    return true otherwise
//    n is the output parameter with the number of (significant) digits in A
// CPSC 1160:
// the ONLY library function that you can use is str.length() and [ ]
bool fromStringToArray(const string &str, int A[], int size, int &n)
{
   n = 0;
   // Check if the string is a Number or not:
   if (!isNumber(str) || str.length() > size)
   {
      return false;
   }
   // Remove all the preeceding zeroes in A string:
   bool Flag = true;
   string modifiedString = "";
   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == '0' && Flag)
      {
         Flag = true;
      }
      else
      {
         Flag = false;
         modifiedString += str[i];
      }
   }
   for (int i = 0; i < modifiedString.length(); i++)
   {
      // Get first value in string
      int num = number(modifiedString[i]);
      // add on the last of an array
      n++;
      A[modifiedString.length() - i - 1] = num;
   }
   return true;
}
// output the n digits of A right justified in a field of fieldWidth columns
// tabSize is the left tab that is full of blanks:
// tabSize is not included in the fieldWidth
// output to std::cout and put the number in a line of its own
// CPSC 1160: 0 is a SPECIAL CASE, output depends on your representation of 0
// precondition:
//    n is the number of significant digits in A i.e. there are no leading zeros
//    n == 0 IS A SPECIAL CASE
void coutBigInt(int A[], int n, int fieldWidth, int tabSize)
{
   for (int i = 0; i < tabSize; i++)
   {
      cout << " ";
   }
   for (int i = n - 1; i >= 0; i--)
   {
      cout << A[i];
   }
   cout << endl;
}
// BONUS
int number(char ch, int base)
{
   switch (ch)
   {
   case 'A':
      return 10;
      break;
   case 'B':
      return 11;
      break;
   case 'C':
      return 12;
      break;
   case 'D':
      return 13;
      break;
   case 'E':
      return 14;
      break;
   case 'F':
      return 15;
      break;
   default:
      int num = ch - 48;
      return num;
      break;
   }
}
bool add(const int A[], int nA, const int B[], int nB, int C[], int &nC, int base)
{
   int carry = 0, sum = 0, value = 0;
   nC = 0;
   int greatestNumber = nA;
   if (nB > nA)
   {
      greatestNumber = nB;
   }
   for (int i = 0; i < nA || i < nB; i++)
   {
      // if elements in array A finishes ,than add only B
      if (i < nA && i < nB)
      {
         sum = A[i] + B[i] + carry;
         carry = 0;
      }
      else if (i >= nA)
      {
         sum = B[i] + carry;
         carry = 0;
      }
      else if (i >= nB)
      {
         sum = A[i] + carry;
         carry = 0;
      }
      if (sum >= base)
      {
         value = sum % base;
         C[i] = value;
         nC++;
         carry = sum / base;
         if (carry > 0 && (i == greatestNumber - 1))
         {
            C[i + 1] = carry;
            nC++;
         }
      }
      else
      {
         value = sum;
         C[i] = value;
         nC++;
      }
   }
   if (nC > 72)
   {
      return false;
   }
   else
   {
      return true;
   }
}
// This fuctio will convert the int C into char C array only when base is higer than 10
void printBaseArray(int C[], int nC, char finalC[], int fieldWidth, int tabSize )
{
   for (int i = 0; i < nC; i++)
   {
      int chr = C[i];
      char value = character(chr);
      finalC[i] = value;
   }
   for (int i = 0; i < tabSize; i++)
   {
      cout << " ";
   }
   for (int i = nC - 1; i >= 0; i--)
   {
      cout << finalC[i];
   }
   cout << endl;
}

bool fromStringToArray(const string &str, int A[], int size, int &n, int base)
{
   n = 0;
   // Check if the string is a Number or not:
   if (str.length() > size)
   {
      return false;
   }
   // Remove all the preeceding zeroes in A string:
   bool Flag = true;
   string modifiedString = "";
   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == '0' && Flag)
      {
         Flag = true;
      }
      else
      {
         Flag = false;
         modifiedString += str[i];
      }
   }
   for (int i = 0; i < modifiedString.length(); i++)
   {
      // Get first value in string
      int num = number(modifiedString[i], base);
      // add on the last of an array
      n++;
      A[modifiedString.length() - i - 1] = num;
   }
   return true;
}

// © 2022 Gladys Monagan
