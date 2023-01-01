// Student Name:Gurdev
// Student Number:100376466
// Test the class Money started by G. Monagan, with doctest
// CPSC 1160, Do not post anywhere

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <sstream> // std::stringstream
#include <string>  // std::string
using namespace std;

#include "Money.h"
TEST_CASE("constructors depend on == and the operator << ")
{
   SUBCASE("no-arg constructor")
   {
      Money m = Money();
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "$0.00");
   }
   SUBCASE("positive dollars, positive cents")
   {
      Money m(7, 83);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "$7.83");
   }
   SUBCASE("0  dollars, negative cents")
   {
      Money m(0, -32);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$0.32");
   }
   SUBCASE("0  dollars, positive cents")
   {
      Money m(0, 99);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "$0.99");
   }
   SUBCASE("negative dollars, negative cents")
   {
      Money m{-10, -21};
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$10.21");
   }
   SUBCASE("negative dollars, positive cents")
   {
      Money m{-10, 25};
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$9.75");
   }
   SUBCASE("positive dollars, negative cents")
   {
      Money m{8, -13};
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "$7.87");
   }
   SUBCASE("negative dollars, positive cents")
   {
      Money m(-2, 92);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$1.08");
   }
}

TEST_CASE("output operator") {
   SUBCASE("only dollars") {
      Money m(7);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "$7.00");
   }
   SUBCASE("positive dollars and positive cents") {
      Money m(345, 67);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "$345.67");
   }
   SUBCASE("negative cents") {
      Money m(0, -32);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$0.32");
   }
   SUBCASE("negative dollars and negative cents") {
      Money m(-31, -32);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$31.32");
   }
   SUBCASE("negative dollars and negative cents") {
      Money m(-10, -21);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$10.21");
   }
   SUBCASE("negative dollars and positive cents") {
      Money m(-10, 25);
      stringstream ss;
      ss << m;
      CHECK(ss.str() == "-$9.75");
   }
}

TEST_CASE("input operator") {
   SUBCASE("positive dollars positive cents") {
      Money m;
      stringstream ss_in("0 77");
      ss_in >> m;
      stringstream ss_out;
      ss_out << m;
      CHECK(ss_out.str() == "$0.77");
   }
   SUBCASE("negative dollars positive cents") {
      Money m;
      stringstream ss_in("-56 21");
      ss_in >> m;
      stringstream ss_out;
      ss_out << m;
      CHECK(ss_out.str() == "-$55.79");
   }
   SUBCASE("negative dollars negative cents") {
      Money m;
      stringstream ss_in("-17 -89");
      ss_in >> m;
      stringstream ss_out;
      ss_out << m;
      CHECK(ss_out.str() == "-$17.89");
   }
   SUBCASE("positive dollars negative cents") {
      Money m;
      stringstream ss_in("43 -26");
      ss_in >> m;
      stringstream ss_out;
      ss_out << m;
      CHECK(ss_out.str() == "$42.74");
   }
}

TEST_CASE("equals operator") {
   SUBCASE("special case") {
      Money x;
      Money y;
      CHECK( x == y );
   }
   SUBCASE("special case different constructor") {
      Money x;
      Money y(0, 0);
      CHECK( x == y );
   }
   SUBCASE("different sign dollars fail") {
      Money x(-8, -25);
      Money y(8, -25);
      CHECK_FALSE( x == y );
   }
   SUBCASE("different sign cents fail") {
      Money x(-3, -25);
      Money y(3, -25);
      CHECK_FALSE( x == y );
   }
   SUBCASE("different signs fail") {
      Money x(-3, -25);
      Money y(3, -25);
      CHECK_FALSE( x == y );
   }
}

TEST_CASE("constants depends on equals")
{
   CHECK(LOONIE == Money(1, 0));
   CHECK(LOONIE == Money(1));
   CHECK(TOONIE == Money(2));
   CHECK(TOONIE == Money(2, 0));
   CHECK(QUARTER == Money(0, 25));
   CHECK(DIME == Money(0, 10));
   CHECK(NICKEL == Money(0, 5));
}

TEST_CASE("less than operator") {
   SUBCASE("less than zero") {
      Money x(0, -1);
      Money y;
      CHECK( x < y );
      CHECK_FALSE( y < x);
   }
   SUBCASE("1 less cent but same dollars") {
      Money x(10, 99);
      Money y(10, 98);
      CHECK(y < x);
      CHECK_FALSE( x < y );
   }
   SUBCASE("negative amounts") {
      Money x(-7, -22);
      Money y(-7, -23);
      CHECK_FALSE( x < y );
      CHECK( y < x );
   }
   SUBCASE("positive amounts") {
      Money x(17, 22);
      Money y(17, 23);
      CHECK( x < y );
      CHECK_FALSE( y < x );
   }
   SUBCASE("equal amounts") {
      Money x(57, 22);
      Money y(57, 22);
      CHECK_FALSE( x < y );
      CHECK_FALSE( y < x );
   }
}

TEST_CASE("greater than operator") {
   SUBCASE("greater than zero") {
      Money x(0, -1);
      Money y;
      CHECK_FALSE( x > y );
      CHECK( y > x );
   }
   SUBCASE("1 less cent but same dollars") {
      Money x(10, 99);
      Money y(10, 98);
      CHECK( x > y );
      CHECK_FALSE(y > x);
   }
   SUBCASE("negative amounts") {
      Money x(-7, -22);
      Money y(-7, -23);
      CHECK( x > y );
      CHECK_FALSE( y > x );
   }
   SUBCASE("positive amounts") {
      Money x(17, 22);
      Money y(17, 23);
      CHECK_FALSE( x > y );
      CHECK( y > x );
   }
   SUBCASE("equal amounts") {
      Money x(57, 22);
      Money y(57, 22);
      CHECK_FALSE( x > y );
      CHECK_FALSE( y > x );
   }
}

TEST_CASE("addition operator")
{
    SUBCASE("add two MOney objects") {
      Money m(12, 99);
      Money m2(10,70);
      stringstream ssLeft;
      ssLeft << (m + m2);
      CHECK(ssLeft.str() == "$23.69");
      stringstream ssRight;
      Money m3(10,-10);
      ssRight << (m3 + m);
      CHECK(ssRight.str() == "$22.89");
    }
   SUBCASE("symmetric with conversion") {
      Money m(12, 99);
      stringstream ssLeft;
      ssLeft << (m + 13);
      CHECK(ssLeft.str() == "$25.99");
      stringstream ssRight;
      ssRight << (13 + m);
      CHECK(ssRight.str() == "$25.99");
   }
   SUBCASE("starting with amount owed with conversion") {
      Money m(-12, -99);
      stringstream ssLeft;
      ssLeft << (m + 13);
      CHECK(ssLeft.str() == "$0.01");
      stringstream ssRight;
      ssRight << (13 + m);
      CHECK(ssRight.str() == "$0.01");
   }
}
TEST_CASE("subtraction operator") {
   SUBCASE("two positive amounts") {
      Money a(8);
      Money b(7, 99);
      stringstream ssLeft;
      ssLeft << (a - b);
      CHECK(ssLeft.str() == "$0.01");
   }
   SUBCASE("negative minus a negative amount") {
      Money a(-9);
      Money b(-1, -98);
      stringstream ssLeft;
      ssLeft << (a - b);
      CHECK(ssLeft.str() == "-$7.02");
   }
   SUBCASE("positive minus a negative amount") {
      Money a(7, 45);
      Money b(-2, -35);
      stringstream ssLeft;
      ssLeft << (a - b);
      CHECK(ssLeft.str() == "$9.80");
   }
}
TEST_CASE("multiplication operator by a factor") {
   SUBCASE("money owed and then paid") {
      Money x(-3, -27);
      stringstream ss;
      ss << (x * -1);
      CHECK(ss.str() == "$3.27");
   }
   SUBCASE("money owed and then doubled") {
      Money x(-3, -27);
      stringstream ss;
      ss << (x * 2);
      CHECK(ss.str() == "-$6.54");
   }
   SUBCASE("money paid by 10 people") {
      Money x(1000);
      stringstream ss;
      ss << (10 * x);
      CHECK(ss.str() == "$10000.00");
   }
}

TEST_CASE("multiplication operator factor by an object") {
   SUBCASE("money owed and then paid") {
      Money x(-3, -27);
      stringstream ss;
      ss << (-1 * x);
      CHECK(ss.str() == "$3.27");
   }
   SUBCASE("money owed and then doubled") {
      Money x(-3, -27);
      stringstream ss;
      ss << (2 * x);
      CHECK(ss.str() == "-$6.54");
   }
   SUBCASE("money paid by 10 people") {
      Money x(1000);
      stringstream ss;
      ss << (x * 10);
      CHECK(ss.str() == "$10000.00");
   }
}

TEST_CASE("multiple multiplications") {
   SUBCASE("back to original price") {
      Money x(4, 99);
      stringstream ss;
      ss << (-1 * x * -1);
      CHECK(ss.str() == "$4.99");
   }
   SUBCASE("several factors first") {
      Money x(-8, 1);
      stringstream ss;
      ss << (2 * 5 * x);
      CHECK(ss.str() == "-$79.90");
   }
   SUBCASE("factors after") {
      Money x(1000);
      stringstream ss;
      ss << (x * 10 * 5);
      CHECK(ss.str() == "$50000.00");
   }
}

TEST_CASE("BONUS unary negative") {
   SUBCASE("from positive to negative") {
      Money m(12345, 67);
      stringstream ss;
      ss << - m;
      CHECK(ss.str() == "-$12345.67");
   }
   SUBCASE("negative plus position equals 0") {
      Money m(33, 81);
      stringstream ss;
      ss << (-m + m);
      CHECK(ss.str() == "$0.00");
   }
   SUBCASE("negative plus negative equals twice negative") {
      Money m(33, 81);
      stringstream ss;
      ss << (-m + -m);
      CHECK(ss.str() == "-$67.62");
   }
   SUBCASE("negative to begin with") {
      Money m(-22, -77);
      stringstream ss;
      ss << -m;
      CHECK(ss.str() == "$22.77");
   }
    SUBCASE("both negative same") {
      Money m(-30, -30);
      stringstream ss;
      ss << -m;
      CHECK(ss.str() == "$30.30");
   }
}

TEST_CASE("BONUS division")
{
   SUBCASE("no rounding") {
      Money bill(7, 50);
      stringstream ss;
      ss << bill/6;
      CHECK(ss.str() == "$1.25");
   }
   SUBCASE("negative money no rounding"   ) {
      Money bill(-3, -75);
      stringstream ss;
      ss << bill/3;
      CHECK(ss.str() == "-$1.25");
   }
   SUBCASE("one is positive"   ) {
      Money bill(10, -75);
      stringstream ss;
      ss << bill/3;
      CHECK(ss.str() == "$3.08");
   }
}
TEST_CASE("BONUS Round off")
{
   SUBCASE("at 500 cents")
   {
      Money bill(7, 500);
      bill.get_dollar();
      stringstream ss;
      ss << bill;
      CHECK(ss.str() == "$8.00");
   }
   SUBCASE("at above than 100 cents cents")
   {
      Money bill(7, 995);
      bill.get_dollar();
      stringstream ss;
      ss << bill;
      CHECK(ss.str() == "$8.00");
   }
   SUBCASE("at lower than  100 cents ")
   {
      Money bill(7, 60);
      bill.get_dollar();
      stringstream ss;
      ss << bill;
      CHECK(ss.str() == "$7.60");
   }
   SUBCASE("at 0.10 cents")
   {
      Money bill(7, 10);
      bill.get_dollar();
      stringstream ss;
      ss << bill;
      CHECK(ss.str() == "$7.10");
   }
   SUBCASE("at 2 cents")
   {
      Money bill(7, 2);
      bill.get_dollar();
      stringstream ss;
      ss << bill;
      CHECK(ss.str() == "$7.02");
   }
}
//are tests for the accessor functions and mutator functions
//-----------------------------------------------------------------
TEST_CASE("accesor functions")
{
   SUBCASE("dollar and cent are same")
   {
      Money m(10, 10);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "10");
      stringstream sb;
      sb << m.getCents();
      CHECK(sb.str() == "10");
   }
   SUBCASE("dollar and cent are different")
   {
      Money m(67, 46);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "67");
      stringstream sb;
      sb << m.getCents();
     
      CHECK(sb.str() == "46");
   }
   SUBCASE("both are 0")
   {
      Money m(0, 0);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "0");
      stringstream sb;
      sb << m.getCents();
     
      CHECK(sb.str() == "0");
   }
   SUBCASE("both negative")
   {
      Money m(-60, -10);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "-60");
      stringstream sb;
      sb << m.getCents();
     
      CHECK(sb.str() == "-10");
   }
   SUBCASE("dollar negative only")
   {
      Money m(-70, 10);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "-69");
      stringstream sb;
      sb << m.getCents();
      CHECK(sb.str() == "-90");
   }
   SUBCASE(" cent are negative")
   {
      Money m(10, 65);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "10");
      stringstream sb;
      sb << m.getCents();
      CHECK(sb.str() == "65");
      stringstream sm;
      sm<< m.getMoney();
      CHECK(sm.str() == "10.65");
   }
   SUBCASE(" get money")
   {
      Money m(10, -70);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "9");
      stringstream sb;
      sb << m.getCents();
      cout<<"m,getcents"<<m.getCents();
      stringstream sm;
      sm<< m.getMoney();
      CHECK(sm.str() == "9.3");
   }
   
}
TEST_CASE("mutator functions")
{
   SUBCASE("dollar and cent are same, +ve")
   {
      Money m(10, 10);
      m.setDollarsCents(30,30);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "30");
      stringstream sb;
      sb << m.getCents();
     
      CHECK(sb.str() == "30");
      stringstream sm;
      sm<< m.getMoney();
       CHECK(sm.str() == "30.3");
   }
   SUBCASE("dollar and cent set -ve")
   {
      Money m(10, 10);
      m.setDollarsCents(-70,-10);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "-70");
      stringstream sb;
      sb << m.getCents();
      
      CHECK(sb.str() == "-10");
      stringstream sm;
      sm<< m.getMoney();
       CHECK(sm.str() == "-70.1");
   }
   SUBCASE("one is positive only")
   {
      Money m(50, -10);
      m.setDollarsCents(-70,-10);
      stringstream ss;
      ss << m.getDollars();
      CHECK(ss.str() == "-70");
      stringstream sb;
      sb << m.getCents();
      CHECK(sb.str() == "-10");
      stringstream sm;
      sm<< m.getMoney();
       CHECK(sm.str() == "-70.1");
   }
   SUBCASE("change directly only money")
   {
      Money m(50, -10);
      m.setAmount(400.10);
      stringstream sm;
      sm<< m.getMoney();
       CHECK(sm.str() == "400.1");
   }
}
