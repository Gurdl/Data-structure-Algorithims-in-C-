// name:Gurdev singh
// id:100376466
#include <ostream>
#include <istream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Money.h"
//-----1 constructor:
// constructor  from two integers,
// the dollars and the cent
Money::Money(int d, int sc)
{
    dollars = d;
    cents = sc;
}
//-----2 constructor:
// constructor for
// single integer: this integer
// corresponds to just the dollars
Money::Money(int d)
{
    dollars = d;
    cents = 0;
}
//-----3 constructor
// default constructor function
// with a no-arg, default constructor
// that sets the Money amount to $0.00
Money::Money()
{
    dollars = 0;
    cents = 0;
}
//-----GET ACCSESSORS----------------------:
//--1. get the dollars (the value returned should be an int):
// this is an accessor function
int Money::getDollars() const
{
    if ((dollars >= 0 && cents >= 0) || (dollars <= 0 && cents <= 0))
    {
        return dollars;
    }
    int realAmountDollar = getMoney();
    return realAmountDollar;
}
// 2.---//get the cents (the value returned should be an int):
// this is an accessor function
int Money::getCents() const
{
    if ((dollars >= 0 && cents >= 0) || (dollars <= 0 && cents <= 0))
    {
        return cents;
    }
    double realAmount = getMoney();
    int dollar = realAmount;
    double cent = realAmount - dollar;
    double c = (cent * 100.0);
    int l = int(c);
    return l;
}
// 3.----//get the Money amount as a double:
// this is an accessor function
double Money::getMoney() const
{
    double finalcent = cents / 100.0;
    double amt = dollars + finalcent;
    return amt;
}
// This function will set the dollar and scents accordingly
void Money::setDollarsCents(int doll, int cen)
{
    dollars = doll;
    cents = cen;
}
// This function will set the amount:
void Money::setAmount(double amount)
{
    int dollar = int(amount);
    double cent = amount - dollar;
    int finalCent = cent * 100;
    setDollarsCents(dollar, finalCent);
}
// This function return true ,if two objects are same
bool operator==(const Money &m1, const Money &m2)
{

    return (m1.getDollars() == m2.getDollars() && m1.getCents() == m2.getCents());
}
// This function will check if the first money object is
// less than second money object;
bool Money::operator<(const Money &m2)
{
    return (getMoney() < m2.getMoney());
}
// This function will check ,if the first money is greater than
// second money object;
bool Money::operator>(const Money &m2)
{
    return (getMoney() > m2.getMoney());
}
// This will  add two money objects :
Money operator+(const Money &m1, const Money &m2)
{
    int cent = m1.getCents() + m2.getCents();
    int carry = 0;
    if (cent >= 100)
    {
        cent -= 100;
        carry++;
    }
    int dollar = m1.getDollars() + m2.getDollars() + carry;
    Money mn(dollar, cent);
    return mn;
}
// This is used to subtract two objects of Money :
Money operator-(const Money &m1, const Money &m2)
{
    int borrow = 0;
    int cent = m1.getCents() - m2.getCents();
    if (cent < 0)
    {
        cent += 100;
        borrow++;
    }
    int dollar = m1.getDollars() - m2.getDollars() - borrow;
    Money mn(dollar, cent);
    return mn;
}
// This function will muptiple the given money object with the n :
Money operator*(const Money &m1, int n)
{
    int dollars = m1.getDollars() * n;
    int cents = m1.getCents() * n;
    Money mn(dollars, cents);
    return mn;
}
// This function is used to multiple n with money object
Money operator*(int n, const Money &m1)
{
    int dollars = m1.getDollars() * n;
    int cents = m1.getCents() * n;
    Money mn(dollars, cents);
    return mn;
}
// iput values:
// This function is used to take inputs
std::istream &operator>>(std::istream &in, Money &m)
{
    int tempDollar, tempCents;
    in >> tempDollar >> tempCents;
    m.setDollarsCents(tempDollar, tempCents);
    return in;
}
// This function is used to give outputs of Money objects
std::ostream &operator<<(std::ostream &out, const Money &m)
{
    if (m.getMoney() >= 0)
    {
        out << "$" << fixed << setprecision(m.DIGITS_OF_CENTS) << m.getMoney();
    }
    else
    {
        out << "-$" << fixed << setprecision(m.DIGITS_OF_CENTS) << -(m.getMoney());
    }

    return out;
}
//-----------------------Bonus------------------------
// the unary minus creates an instance of the negation of the amount
// (if positive to negative and if negative to positive)
Money operator-(const Money &m)
{
    Money mn(-m.getDollars(), -m.getCents());
    return mn;
}
// Bonus Question : Division of money object by n number
//This function divide the given money of m 
// into n persons almost equally 
Money operator/(Money m, const int &n)
{
    double amount = m.getMoney();
    double finalAmount = amount / n;
    m.setAmount(finalAmount);
    return m;
}
// Bonus Quesion:
//This function will roud off the money amount
void Money::get_dollar()
{
    int cent = getCents();
    if (cent >= 100)
    {
        int dollar = 1 + getDollars();
        setDollarsCents(dollar, 0);
    }
}
