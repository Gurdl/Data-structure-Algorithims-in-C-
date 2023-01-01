// Name:Gurdev singh
// Student Number:100376466
// A class to represent money with dollars and cents
// CPSC 1160, Do not post anywhere
#ifndef MONEY_H
#define MONEY_H
using namespace std;
#include <iostream>
class Money
{
public:
   // creates an instance worth $0 dollars and 0 cents
   Money();
   // creates an instance worth $d dollars (d may be positive, negative, or 0)
   // plus or minus c cents (depending on whether c is positive, negative, or 0)
   // precondition:  |cents| < 100
   Money(int dollars, int cents);
   // creates an instance worth $justDollars dollars
   // (justDollars may be positive, negative, or 0)
   Money(int justDollars);
   //-----GET ACCSESSORS----------------------:
   //--1. get the dollars (the value returned should be an int):
   // this is an accessor function
   int getDollars() const;
   // 2.--get the cents (the value returned should be an int):
   // this is an accessor function
   int getCents() const;
   // 3.----//get the Money amount as a double:
   // this is an accessor function
   double getMoney() const;
   //---------------Mutator function:
   // read two integers
   // the first integer corresponds to the dollars
   // set the dollars and cents with two integers in a single function:
   // this is a mutator function
   void setDollarsCents(int dollars, int scents);
   // set the dollars and cents with an amount of type double:
   // this is a mutator function
   void setAmount(double amount);

   // binary operator returns true if two Money objects are equal,
   //  false otherwise
   friend bool operator==(const Money &m1, const Money &m2);
   // binary operator returns true if the first Money object is less than the second Money object,
   // false otherwise
   bool operator<(const Money &m2);
   // binary operator returns true if the first Money object is greater than the second Money object,
   // false otherwise
   bool operator>(const Money &m2);
   // This function will add two money object and will return
   // a money object:
   friend Money operator+(const Money &m1, const Money &m2);
   // friend Money operator +( int n,const Money& m2);
   // This function will be add a number into an
   //  money object:
   // This function is used to subtract two money objects :
   friend Money operator-(const Money &m1, const Money &m2);
   // This function is used to mulptiple the money object with
   // Given number:
   friend Money operator*(const Money &m1, int n);
   friend Money operator*(int n, const Money &m1);

   // the second integer corresponds to the cents
   // assume that the user enters exactly two integers (no error checking needed)
   // the second integer corresponding to cents has an absolute
   // value of less than 100
   // either integer could be positive, negative or zero
   friend std::istream &operator>>(std::istream &in, Money &m);
   // output in the form    $ddd.cc     with Money::DIGITS_OF_CENTS
   // after the fixed decimal point
   // there could possibly a negative sign before the $ sign
   friend std::ostream &operator<<(std::ostream &in, const Money &m);

   // number of decimal places after the decimal point
   static const int DIGITS_OF_CENTS = 2;

   // BONUS
   // the unary minus creates an instance of the negation of the amount
   // (if positive to negative and if negative to positive)
   friend Money operator-(const Money &m);

   // BONUS
   // divide the money amount by n
   // precondition:
   //   n cannot be zero
   friend Money operator/(Money m, const int &n);
   // Bonus:
   // round off the fiven value:
   void get_dollar();

private:
   int dollars;
   int cents;
};
// define some coins as constants
const Money LOONIE(1, 0);
const Money TOONIE(2);
const Money QUARTER(0, 25);
const Money DIME(0, 10);
const Money NICKEL(0, 5);
#endif // MONEY_H
