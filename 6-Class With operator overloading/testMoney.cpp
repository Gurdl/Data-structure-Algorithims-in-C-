// Test the class Money by Gladys Monagan
// Because the names of the accessor functions were not given in the 
// assignment, this test file would need to be expanded instead of having to
// "eyeball" the answer
// CpSc 1160

#include "Money.h"
#include <iostream>
#include <string>
using namespace std;
using std::string;

// // equal tests to see if x and y are equal
bool equal(const Money& x, const Money& y)
{
   return(x.getMoney()==y.getMoney());
   
}
void testEqual(const std::string& str, const Money& x, const Money& y) {
   cout <<  "\ncompare " << x << " with " << y;
   if (!equal(x,y))
      cout << "ERROR:" << x << " should be equal to " << y << endl;
   else
      cout << " with expected value of " << str << endl;
}

// test the constructors and the output operator
// compareValues would presumably use the accessor functions
void compareValues(int dollars, int cents, int expected_dollars, int expected_cents)
{
   if(dollars!=expected_dollars ||cents!=expected_cents)
   {
      cout<<dollars<<"ERROR:dollar is not equal to"<<expected_dollars<<endl;
      cout<<cents<<" ERROR:cents is not equal to"<<expected_cents;
   }
   else
   {
      cout<<dollars<<"dollar is  equal to"<<expected_dollars<<endl;
      cout<<cents<<" cents is  equal to"<<expected_cents;

   }

}
void testConstructors() {   
   // test the no-arg constructor
   Money m = Money(); 
   cout << endl;
   cout << "Money()   \t" << m << endl;
   cout << "expecting \t" << "$0.00" << endl;
   int expected_dollars = 0;
   int expected_cents = 0;
   int dollars=m.getDollars();
   int cents=m.getCents();
   compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // positive dollars, positive cents
   Money a(7, 83);
   cout << "Money(7, 83) \t" << a << endl;
   cout << "expecting    \t" << "$7.83" << endl;
   expected_dollars = 7;
   expected_cents = 83;
   dollars=a.getDollars();
    cents=a.getCents();
    compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // 0  dollars, negative cents
   Money b(0, -32);
   // cout << "Money(0, -32)\t" << b << endl;
   // cout << "expecting    \t" << "-$0.32" << endl;
   expected_dollars = 0;
   expected_cents = -32;
   dollars=b.getDollars();
    cents=b.getCents();
   compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // 0  dollars, positive cents
   Money c(0, 99);
   cout << "Money(0, 99)\t" << c << endl;
   cout << "expecting   \t" << "$0.99" << endl;
   expected_dollars = 0;
   expected_cents = 99;
   dollars=c.getDollars();
    cents=c.getCents();
    compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // negative dollars, negative cents
   Money d{-10, -21};
   cout << "Money d{-10, -21}\t" << d << endl;
   cout << "expecting        \t" << "-$10.21" << endl;
   expected_dollars = -10;
   expected_cents = -21;
   dollars=d.getDollars();
    cents=d.getCents();
    compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // negative dollars, positive cents
   Money e = Money{-10, 25};
   cout << "Money{-10, 25}\t" << e << endl;
   cout << "expecting     \t" << "-$9.75" << endl;
   expected_dollars = -9;
   expected_cents = -75;
   dollars=e.getDollars();
    cents=e.getCents();
    compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // positive dollars, negative cents
   Money f{8, -13};
   cout << "Money f{8, -13}\t" << f << endl;
   cout << "expecting     \t" << "$7.87" << endl;
   expected_dollars = 7;
   expected_cents = 87;
   dollars=f.getDollars();
    cents=f.getCents();
   compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
   
   // negative dollars, positive cents
   Money g(-2, 92); 
   cout << "Money g(-2, 92)\t" << g << endl;
   cout << "expecting     \t" << "-$1.08" << endl;
   expected_dollars = -1;
   expected_cents = -8;
   dollars=g.getDollars();
    cents=g.getCents();
    compareValues(dollars, cents, expected_dollars, expected_cents);
   cout << endl;
}

// note the symmetry expected
void testAddition() {
   cout << "\ntesting addition..........";
   Money m = Money(12, 99);
   testEqual("25.99", m + 13, 13 + m);
   
   m.setDollarsCents(-12, 0);
   testEqual("1.00", m + 13, 13 + m);
}

// note the symmetry expected
void testSubtraction() {
    cout << "\ntesting subtraction..........";
    Money m = Money(12, 1);
    testEqual("-$0.99", m - 13, Money(0, -99));
    m = Money(12, 1);
    testEqual("-$5.01", (7 - m), Money(-6, 99));
}

void testMultiplication() {
   cout << "\ntesting multiplication..........";
   Money m(-3, -27);
   testEqual("$3.27", m * -1, Money() - m);
   testEqual("$3.27", -1 * m, Money() - m);

   testEqual("-$6.54", m * 2, Money(-6, -54));
   m = Money(0, 3);
   testEqual("$3.00", Money(3, 0), m * 100);
   testEqual("$3.00", Money(3, 0), 100 * m);
   m = m * 2 * 5;
   testEqual("$30.00", Money(30), m * 100);
}

void testDivisionUsingBill() {
   cout << "\ntesting division..........";
   Money billA(7, 50);
   Money billB(3, 75);
   testEqual("1.25", billA/6, billB/3);
}


int main() {
  // from assignment sheet
//   Money m1(10,10);
//   Money m2(10,20);
//   cout<<"The Two object are equal ?"<<(m1==m2);
  

   Money m0(0, -32) ;
   cout << m0 << "\texpecting -$0.32 " << endl;
   Money m1(-10, -21);
   cout << m1 << "\texpecting -$10.21 " << endl;
   Money m2(-10, 25); 
   cout << m2 << "\texpecting -$9.75 " << endl;

   testConstructors();
   testAddition();
   testSubtraction();
   testMultiplication();
   testDivisionUsingBill();
   


   return 0;
}

// copyright 2022 Gladys Monagan 

