// Author: Gladys Monagan
// Do not submit.
// Do not post anywhere.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <sstream>  // std::stringstream
#include <iostream>
#include <string> 
#include "poly.h"

using std::stringstream, std::string;

TEST_CASE("zero polynomial") {
   Sparse f;
   SUBCASE("output") {
      stringstream actual;
      actual << f;
      CHECK( actual.str() == "0" );
   }
   SUBCASE("isZeroSparse") {
      CHECK(f.isZeroSparse());
   }
   SUBCASE("degree") {
      CHECK_EQ(f.degree(), -1);
   }
   SUBCASE("coefficient") {
      CHECK_EQ(f.coefficient(5), 0);
   }
   SUBCASE("multiplication") {
      Sparse result = f * 7;
      CHECK(result.isZeroSparse());
   }
   SUBCASE("sum") {
      Sparse g;
      CHECK((f + g).isZeroSparse());
   }
   SUBCASE("sum") {
      Sparse g;
      CHECK((f - g).isZeroSparse());
   }
 }

TEST_CASE("one term constructor") {
   Sparse f(3, 2);
   SUBCASE("output") {
      stringstream actual;
      actual << f;
      CHECK( actual.str() == "3*x^2" );
   }
   SUBCASE("isZeroSparse") {
      CHECK_FALSE( f.isZeroSparse() );
   }
   SUBCASE("degree") {
      CHECK_EQ( f.degree(), 2 );
   }
   SUBCASE("coefficient") {
      CHECK_EQ( f.coefficient(2), 3 );
      CHECK_EQ( f.coefficient(5), 0 );
   }
   SUBCASE("multiply") {
      stringstream actual;
      actual << (f * -2);
      CHECK( actual.str() == " - 6*x^2" );
   }
   SUBCASE("variable name") {
      CHECK( f.getPrintVariable() == 'x' );
   }
   SUBCASE("multiply by 0") {
      stringstream actual;
      CHECK( (f * 0).isZeroSparse() );
   }
}

TEST_CASE("insert one term") {
   Sparse f;
    stringstream ss_in("1 3 2");
    ss_in >> f;
   SUBCASE("output") {
      stringstream actual;
      actual << f;
      CHECK( actual.str() == "3*x^2" );
      stringstream ss_in2("1 4 5");
      ss_in2 >> f;
      stringstream actual2;
       actual2 << f;
       CHECK( actual2.str() == "3*x^2 + 4*x^5" );
       stringstream ss_in3("1 2 3");
      ss_in3 >> f;
      stringstream actual3;
       actual3 << f;
       CHECK( actual3.str() == "3*x^2 + 2*x^3 + 4*x^5" );

   }
   SUBCASE("isZeroSparse") {
      CHECK_FALSE( f.isZeroSparse() );
   }
   SUBCASE("degree") {
      CHECK_EQ( f.degree(), 2 );
   }
   SUBCASE("coefficient") {
      CHECK_EQ( f.coefficient(2), 3 );
      CHECK_EQ( f.coefficient(5), 0) ;
   }
   SUBCASE("multiply") {
      stringstream actual;
      actual << (f * 2);
      CHECK( actual.str()== "6*x^2" );
   }
   SUBCASE("SUM")
   {
      stringstream actual;
      actual << (f + f);
      CHECK(actual.str()=="6*x^2");
      stringstream actual2;
      Sparse l(3,9);
      actual2 << (f + l+f);
      CHECK(actual2.str()=="12*x^2 + 3*x^9");
       Sparse m(10,9);
       stringstream actual3;
       actual3 << (f + l+f+m);
      CHECK(actual3.str()=="24*x^2 + 13*x^9");
      Sparse n(10,3);
       stringstream actual4;
       actual4 << (f +l+n);
      CHECK(actual4.str()=="24*x^2 + 10*x^3 + 3*x^9");

   }
   SUBCASE("dervative")
   {
      stringstream actual;
      Sparse f(3,5);
      actual << f.derivative();
      CHECK(actual.str()=="15*x^4");
   }

   SUBCASE("multiply by 0") {
      stringstream actual;
      CHECK( (f * 0).isZeroSparse() );
   }
}
TEST_CASE("dervative") 
{
   SUBCASE("dervative with one value")
   {
   stringstream actual;
      Sparse f(8,5);
      actual << f.derivative();
      CHECK(actual.str()=="40*x^4");
   }
  SUBCASE("dervative with one value")
   {
   Sparse f;
    stringstream ss_in("2 3 2 4 6");
    ss_in >> f;
    stringstream actual;
     actual << f.derivative();
      CHECK(actual.str()=="6*x^1 + 24*x^5");
   }
}


// copyright 2022 Gladys Monagan

