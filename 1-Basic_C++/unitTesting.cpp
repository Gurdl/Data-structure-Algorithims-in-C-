#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
g++ -pedantic -Wall -Wextra -std=c++17 power_unitTesting.cpp -o unitTesting
*/
#include "doctest.h"
#include "inflation.cpp"
TEST_CASE("Special cases")
{
//same values before and after the year
 CHECK(calculateInflation(2.0,2.0)==0.0);
 //after one year,When  if values slightly changes
 CHECK(calculateInflation(2.0,4.0)==100.0);
 CHECK(calculateInflation(2.0,6.0)==200.0);
}
TEST_CASE("Special cases")
{
//same values before and after the year
 CHECK(calculateInflation(2.0,2.0)==0.0);
 //after one year,When  if values slightly changes
 CHECK(calculateInflation(2.0,4.0)==100.0);
 CHECK(calculateInflation(2.0,6.0)==200.0);
}
TEST_CASE("border  cases")
{
/*
  https://github.com/doctest/doctest/blob/master/doc/markdown/assertions.md#floating-point-comparisons
*/
//when peices are too close:
  CHECK(calculateInflation(3.0,3.004)==doctest::Approx(0.1333).epsilon(0.01));
  CHECK(calculateInflation(3.0,3.9)==doctest::Approx(30.0));
  CHECK(calculateInflation(3.01,3.02)==doctest::Approx(0.33).epsilon(0.01));
  
}
TEST_CASE("Large inflation cases")
{
    
  CHECK(calculateInflation(3.0,50090.0)==doctest::Approx(1669566.66).epsilon(0.01));

}
TEST_CASE("Negative inflation cases")
{
    
  CHECK(calculateInflation(7.0,4.0)==doctest::Approx(-42.857).epsilon(0.001));

}



