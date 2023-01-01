// Name: Gurdev singh
// Student Number: 100376466
// Do not post anywhere.

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>   // std::max part of the STL
#include "BigInts.h"   // BIGGEST_BASE writeBigInt add subtract and multiply

using std::string, std::ostream, std::istream, std::endl, std::cin, std::cout;

////////////////////////////////////////////////////////////////////////////////
// global constant which should be set to true if the bonus is done
const int BONUS_DONE = true;

const char BLANK = ' ';

// get the maximum of the three digits
int getMax(int x, int y, int z) {
   return std::max(std::max(x, y), z);
}

void printInstructionsGetBase(int& base, istream& in = cin, ostream& out = cout) {
   if (BONUS_DONE) {
      out << "In which base should the computations happen?";
      out << "\ne.g. enter 2 for binary, 10 for decimal, 16 for hexadecimal\n";
      out << "Enter base (2 <= base <= " << BIGGEST_BASE << ") : ";
      in>>base;
      while(base!=2 && base!=10 && base != BIGGEST_BASE){
         cout<<"Reneter only mentioned base"<<endl;
         in>>base;
      }
   }
   else 
   {
      base = 10;
      cout<<"You can only use base =10";
   }
   out << endl;
   out << "enter a non negative integer\n";
   out << "enter an operator (possibilities are + - *)\n";
   out << "enter a non negative integer\n\n";
   out << "for subtraction a - b:\n";
   out << "   if a and b are equal, subtraction is a - b\n";
   out << "   otherwise, it is the larger operand minus the smaller operand\n";
   out << endl;
}

// print out the operator op in the middle of the tabSize
// precondition:
//    tabSize  >= 2
//    the string op is of length 1
void printOperator(ostream& out, char op, int tabSize) {
   for (int i = 0; i < tabSize/2; i++) out << BLANK;
   out << op << endl;
}

// print out a line of n underscores preceded by a BLANK
void printBottomLine(ostream& out, int n) {
   out << BLANK;
   for (int i = 0; i < n; i++) out << '_';
   out << endl;
}

// output the n digits in a right justified field of fieldWidth columns
// tabSize is the left tab that is full of BLANKs 
// (tabSize is not included in the fieldWidth)
// precondition:
//    numberofDigits for BigInts is implemented correctly
//    printBigInts is implemented correctly
void printBigInt(ostream& out, const BigInt * x, int fieldWidth, int tabSize) {
   int n = numberOfDigits(x);
   int numBlanks = fieldWidth - n + tabSize;
   for (int i=0; i < numBlanks - 1; i++) out << BLANK;
   writeBigInt(out, x);
}

// output one per line two BigInts and a single operator
// put the bottom line as well
void printBigIntsAndOp(ostream& out, const BigInt* x, const BigInt* y, char op, 
   int width, int tabSize) {
   out << endl;
   printBigInt(out, x, width, tabSize);
   out << endl;
   printOperator(out, op, tabSize);
   printBigInt(out, y, width, tabSize);
   out << endl;
   printBottomLine(out, tabSize + width);
}

// ask for the base from standard input
// read two big numbers and an operator
// do the arithmetic operation
// print out the numbers and the result
// ask whether the operation should be repeated
int main() {
   // for nice output put TAB_SIZE blanks at the beginning and use TAB_SIZE
   const int TAB_SIZE = 5;
   
   int base;
   cout<<"Which base operations you need"<<endl;
   printInstructionsGetBase(base, cin, cout);
   string answer=""; 
// for asking whether the user to continue or not
   do {
      cout << endl;
      cout<<"Enter any non negetive number"<<endl;
      // int a;
      // cin>>a;
      BigInt *x = readBigInt(cin, base);
      cout<<"write operator :"<<endl;
      // char c;
      // cin>>c;
      char op = readOperator(cin);
       cout<<"Enter any non negetive number"<<endl;
      // int b;
      // cin>>b;
      BigInt *y = readBigInt(cin, base);   
      BigInt *z;
      switch (op) {
         case '+':
            z = add(x, y, base);
            break;
         case '-':
            if (isGreaterThan(y, x)) {
               BigInt* tmp = x;
               x = y;
               y = tmp;
            }
            z = subtract(x, y, base);
            break;
         case '*':
            z = multiply(x, y, base);
            break;
         default:
            z = nullptr;
            std::cerr << "ERROR, the operator " << op << " is not supported\n";
      }
      int width = getMax(numberOfDigits(x), numberOfDigits(y), numberOfDigits(z));
      printBigIntsAndOp(cout, x, y, op, width, TAB_SIZE);
      printBigInt(cout, z, width, TAB_SIZE);
      deleteBigInt(x);
      deleteBigInt(y);
      deleteBigInt(z);
      cout << "\n\ncontinue? (y/n): ";
      cin >> answer;
   }  while (answer == "y" || answer == "Y");
   return 0;
}

// copyright 2022 Gladys Monagan 
