// Name: Gladys Monagan
// Student Number: 123456789
// CPSC 1160, Do not post anywhere

#ifndef BIGINTS_H
#define BIGINTS_H

#include <iostream>
#include <string>
// main data structure to store the big integer
struct BigInt
 {
   int numDigits; // the number of digits
   int * digits;  // an array of numDigits digits 
};
// Check if the given string is a number or not:
// PreCondition:
// Only A string must be passed
// PostCondition:
// if a string is a number ,True will be returned
bool isNumber(std::string str,int base);

// the base cannot be greater than hexadecimal
// needed for the bonus
const int BIGGEST_BASE = 16;

// given a character ch in a base, return its numerical equivalent
// precondition:
//   2 <= base <= BIGGEST_BASE
// postcondition:
//   return ch as a number
//   return -1 if not a valid digit in the base
int number(char ch, int base = 10);

// convert the digit d into a character
// precondition:
//    0 <= d < BIGGEST_BASE
// postcondition:
//    0 -> '0'   1 -> '1' .... 10 ->'A'  11 -> 'B' .... 15 -> 'F'
char character(int d);

// allocate space and define the zero constant as a BigInt
// and put the one constant 0 in it
BigInt* zeroConstant();

// returns the number of digits in the BigInt
int numberOfDigits(const BigInt* x) ;

// read a big integer (a string) from the open stream "in"
// convert each character of the string read into a digit using the base 
// (defaulted to 10)
// store all the digits read into a dynamic array in the BigInt 
// without any leading zeros
//
// if the string read has INVALID digits, 
// output an error message with std::err and ask the user to try again
// until a successful number (string) is read
// precondition:
//     2 <= base <= BIGGEST_BASE
// postcondition:
//    return a pointer to the newly allocated BigInt
//    there are no leading zeros stored
//    suggestion: store the digits from least significant to most significant
BigInt* readBigInt(std::istream& in, int base = 10);

// read the operator as a character from the open stream "in"
// keep reading until one of the valid operators is read
// '+' ' -' or '*' is read
// if the operator read is INVALID, 
// output an error message with std::err and ask the user to try again
// until a successful operator is read
// postcondition:
//    return the operator either '+' or '-' or '*'
char readOperator(std::istream& in);

// outputs a big number to the open output stream "out"
void writeBigInt(std::ostream& out, const BigInt* x) ;

// x plus y returning the sum as a pointer to a newly allocated BigInt
// do the addition in base 'base'
// precondition:
//    suggestion:
//    the digits of x and y are stored from least significant to most significant
//    there are no leading zeros in the result
// postcondition:
//    returned a newly allocated BigInt which representing the sum x + y
//    there are no leading zeros in the result
BigInt * add(const BigInt* x, const BigInt* y, int base = 10);

// x minus y returning the difference as a pointer to a BigInt
// do the subtraction in base 'base'
// precondition:
//    x >= y so that the result will not be negative
//    suggestion:
//    the digits of x and y are stored from least significant to most significant
// postcondition:
//    returned a newly allocated BigInt which representing the difference x - y
//    there are no leading zeros in the result
BigInt* subtract(const BigInt* x, const BigInt* y, int base = 10);

// x times y returning the product as a pointer to a BigInt
// do the multiplication in base 'base'
// precondition:
//    suggestion:
//    the digits of x and y are stored from least significant to most significant
// postcondition:// add more functions as needed
//    returned a newly allocated BigInt which representing the product x * y
//    there are no leading zeros
BigInt *multiply(const BigInt* x, const BigInt* y, int base = 10);

// determine if x (the first argument) is greater than y (the second argument)
// precondition:
//    there are no leading zeros
// postcondition
//   return true if x is greater than y, otherwise return false
bool isGreaterThan(const BigInt* x, const BigInt* y);

// deallocate the memory allocated for the BigInt and set x to the nullptr
// postcondition:
//    x is the nullptr (x is passed by reference)
void deleteBigInt(BigInt* &x);

// add more functions as needed

#endif

// copyright 2022 Gladys Monagan

