// Name:Gurdev singh
// Student Number:100376466
// CPSC 1160, Do not post anywhere

#include "BigInts.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <string>

using namespace std;
// given a character ch in a base, return its numerical equivalent
// precondition:
//   2 <= base <= BIGGEST_BASE
// postcondition:
//   return ch as a number
//   return -1 if not a valid digit in the base
int number(char ch, int base)
{
   if (base <= 16)
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
   else
   {
      return ch + 0;
   }
}

// convert the digit d into a character
// precondition:
//    0 <= d < BIGGEST_BASE
// postcondition:
//    0 -> '0'   1 -> '1' .... 10 ->'A'  11 -> 'B' .... 15 -> 'F'
char character(int d)
{
   switch (d)
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
      char ans = (char)(48 + d);
      return ans;
      break;
   }
}

// allocate space and define the zero constant as a BigInt
// and put the one constant 0 in it
BigInt *zeroConstant()
{
   BigInt *value = new BigInt;
   value->numDigits = 1;
   value->digits = new int[1];
   value->digits[0] = 0;
   return value;
}

// returns the number of digits in the BigInt
int numberOfDigits(const BigInt *x)
{
   const int number = x->numDigits;
   return number;
}

BigInt *readBigInt(istream &in, int base)
{
   string str;
   in >> str;
   while (!isNumber(str, base))
   {
      cout << "\nWrong input in base: "<<base<<", the value must belong to base"<<endl;
      in >> str;
   }
   // Remove all the preeceding zeroes in A string:
   bool Flag = true;
   string modifiedString = "";
   int strLength = str.length();
   for (int i = 0; i < strLength; i++)
   {
      // skipp all the leading zeroes
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
   // create object of struct type:
   // if string contains all zeres:
   BigInt *numberObject;
   if (modifiedString == "")
   {
      numberObject = zeroConstant();
   }
   else
   {
      numberObject = new BigInt;
      int length = modifiedString.length();
      numberObject->numDigits = length;
      numberObject->digits = new int[length];
      int j = 0;
      for (int i = length - 1; i >= 0; i--)
      {
         char ch = modifiedString[i];
         int value = number(ch, base);
         numberObject->digits[j++] = value;
      }
   }
   // created an array
   // create an array to store the values:

   // struct BigInt* ptr=&numberObject;
   return numberObject;
}
// Check if the given string is a number or not:
// PreCondition:
// Only A string must be passed
// PostCondition:
// if a string is a number ,True will be returned
bool isNumber(string str, int base)
{
   // for base 16:
   if (base == 16)
   {
      int length = str.length();
      for (int i = 0; i < length; i++)
      {

         if ((isdigit(str[i])) || str[i] == 'A' || str[i] == 'B' || str[i] == 'C' || str[i] == 'D' ||
             str[i] == 'E' || str[i] == 'F')
         {
            return true;
         }
      }
      return false;
   }
   //for base 10
   else if (base == 10)
   {
      int length = str.length();
      for (int i = 0; i < length; i++)
      {

         if (!isdigit(str[i]))
         {
            return false;
         }
      }
      return true;
   }
   //for base 2:
   else
   {
      int length = str.length();
      for (int i = 0; i < length; i++)
      {

         if (str[i]!='0' && str[i]!='1')
         {
            return false;
         }
      }
      return true;

   }

}

// read the operator as a character from the open stream "in"
char readOperator(istream &in)
{
   char c;
   in >> c;
   // std::err("wromh ")
   if (c == '-')
   {
      return '-';
   }
   else if (c == '+')
   {
      return '+';
   }
   if (c == '*')
   {
      return '*';
   }
   else
   {
      std::cerr << "ERROR, the operator " << c << " is not supported\n";
      do
      {
         cout << "\nTry new operator" << endl
              << " you entered" << c << endl;
         cin >> c;
      } while (c != '-' && c != '+' && c != '*');
      return c;
   }
}

// outputs a big number to the open output stream "out"
void writeBigInt(ostream &out, const BigInt *x)
{
   const int number = (x->numDigits);
   for (int i = number - 1; i >= 0; i--)
   {
      int value = x->digits[i];
      char ch = character(value);
      out << ch;
   }
}
// a plus b returning the sum
// do the addition in base 'base'
// precondition:
//    the digits of a and b are stored from least significant to most significant
// postcondition:
//    returned a newly allocated BigInt which representing the sum x + y
BigInt *add(const BigInt *a, const BigInt *b, int base)
{

   int nC = 0;
   int nA = a->numDigits; // length of a array
   int nB = b->numDigits; // length of b array
   int *A = a->digits;
   int *B = b->digits;
   int carry = 0;
   int sum = 0;
   int value = 0;
   int greatestNumber = nA;
   if (nB > nA)
   {
      greatestNumber = nB;
   }
   int *c = new int[greatestNumber + 1]; // Array to store their sum
   // struct BigInt* cObject;

   //  cObject->digits=new int[greatestNumber];
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
         c[i] = value;
         nC++;
         carry = sum / base;
         if (carry > 0 && (i == greatestNumber - 1))
         {
            c[i + 1] = carry;
            nC++;
         }
      }
      else
      {
         value = sum;
         c[i] = value;
         nC++;
      }
   }
   BigInt *cObject;
   cObject = new BigInt;
   cObject->numDigits = nC;
   cObject->digits = c; // final size of an array;
   //now delete the other array as it is not required;
   return cObject;
}

// return x - y
// do the subtraction in base 'base'
// precondition:
//    x >= y so that the result will not be negative
//    the digits of a and b are stored from least significant to most significant
// postcondition:
//    returned in the allocated BigInt the digits' difference and number of digits
//    the digits of the resulting BigInt are stored from least to most significant
BigInt *subtract(const BigInt *x, const BigInt *y, int base)
{
   int nC = 0;
   int nA = x->numDigits; // length of a array
   int nB = y->numDigits; // length of b array
   int *A = x->digits;
   int *B = y->digits;

   int borrow = 0;
   int sub = 0;
   int value = 0;
   int greatestNumber = nA;
   if (nB > nA)
   {
      greatestNumber = nB;
   }
   int *c = new int[greatestNumber]; // Array to store their sum
   // struct BigInt* cObject;

   //  cObject->digits=new int[greatestNumber];
   for (int i = 0; i < nA || i < nB; i++)
   {
      // if elements in array A finishes ,than add only B
      if (i < nA && i < nB)
      {
         sub = A[i] - B[i] - borrow;
         borrow = 0;
      }
      else if (i >= nA)
      {
         sub = B[i] - borrow;
         borrow = 0;
      }
      else if (i >= nB)
      {
         sub = A[i] - borrow;
         borrow = 0;
      }
      if (sub < 0)
      {
         sub += base;
         borrow = 1;
      }
      value = sub;
      c[i] = value;
      nC++;
   }
   BigInt *cObject;
   cObject = new BigInt;
   int count = 0;
   int *finalSub = new int[nC];
   bool flag = true;
   for (int i = nC - 1; i >= 0; i--)
   {
      if (c[i] == 0 && flag)
      {
         flag = true;
      }
      else
      {
         finalSub[i] = c[i];
         count++;
         flag = false;
      }
   }
   // if there is no value added ,all are zero:
   if (count == 0)
   {
      count++;
      finalSub[0] = 0;
   }
    //now delete the other array as it is not required:
   cObject->numDigits = count;
   cObject->digits = finalSub; // final size of an array;
   return cObject;
}

// x times y returning the product as a pointer to a BigInt
// do the multiplication in base 'base'
// precondition:
//    suggestion:
//    the digits of x and y are stored from least significant to most significant
// postcondition:
//    returned a newly allocated BigInt which representing the product x * y
//    there are no leading zeros
BigInt *multiply(const BigInt *x, const BigInt *y, int base)
{
   int nA = x->numDigits;
   int *A = x->digits;
   int nB = y->numDigits;
   int *B = y->digits;
   int nC = 0;
   int greatestNumber = nA + nB;
   int *C = new int[greatestNumber + 1];
   std::fill(C, C + greatestNumber, 0);
   for (int j = 0; j < nB; j++)
   {
      int carry = 0;
      int carryAdd = 0;
      int valueAtB = B[j];
      int k = j;
      for (int i = 0; i < nA; i++)
      {

         int valueAtA = A[i];
         int mult = valueAtA * valueAtB + carry;
         if (mult >= base)
         {
            carry = mult / base;
            mult = mult % base;
         }
         // cout<<"\n, mult:"<<mult<<" ,carry :"<<carry;
         if (j > 0)
         {
            int vl = C[k] + mult + carryAdd;
            if (vl >= 10)
            {
               carryAdd = vl / base;
               vl = vl % base;
               C[k] = vl;
            }
            else
            {
               C[k] = vl;
               carryAdd = 0;
            }
         }
         else
         {
            C[k] = mult;
         }
         k++;
         // check whether it is last element ,which left as carray:
         int val = i + 1;
         if (carry > 0 && val >= nA)
         {
            C[k] = C[k] + carry + carryAdd;
            k++;
         }
         nC = k;
      }
   }
   BigInt *multObject;
   multObject = new BigInt;
   multObject->numDigits = nC;
   multObject->digits = C;
   return multObject;
}

// deallocate the memory allocated for the BigInt and set x to the nullptr
// postcondition:
//    x is the nullptr (x is passed by reference)
void deleteBigInt(BigInt *&x)
{
   delete[] x->digits;
   delete x;
   x = nullptr;
}

// determine if x is greater than y
// precondition:
//    there are no leading zeros
// postcondition
//   return true if x is greater than y, otherwise return false

bool isGreaterThan(const BigInt *x, const BigInt *y)
{
   if ((x->numDigits) > (y->numDigits))
   {
      return true;
   }
   return false;
}

// copyright 2022 Gladys Monagan
