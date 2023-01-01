// Name: Gurdev singh
//

/*
g++ -pedantic -Wall -Wextra  -std=c++17 bigInts_unittest.cpp -o bigInts_unittest
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// it is terrible programming style to #include an implementation cpp file    //
//      we are only doing this at the beginning of the course                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
#include "bigInts.cpp"
#include <string>
using namespace std;
using std::string;

// determine if the first n elements of A and B are equal returning true
// if equal false, otherwise
// return false if the number of elements to compare is greater than MAX_DIGITS
bool equalValues(const int A[], const int B[], int n, int MAX_DIGITS) {
   if (n > MAX_DIGITS)
      return false;
   for (int i = 0; i < n; i++){
      if (A[i] != B[i])
      {
         return false;
      }
   }
   return true;
}

//------------------------------------------------------------------------------
// starting tests for fromStringToArray
//------------------------------------------------------------------------------
TEST_CASE("typical all the digits") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS];
   int n;
   CHECK(fromStringToArray(string("12345678900"), A, MAX_DIGITS, n));
   int EXPECTED[MAX_DIGITS] = {0, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   CHECK(equalValues(A, EXPECTED, n, MAX_DIGITS));
}

TEST_CASE("leading zeros") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS];
   int n;
   CHECK(fromStringToArray(string("0000000099"), A, MAX_DIGITS, n));
   int EXPECTED[MAX_DIGITS] = {9, 9};
   CHECK(equalValues(A, EXPECTED, n, MAX_DIGITS));
}

TEST_CASE("spurious characters") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS];
   int n;
   CHECK_FALSE(fromStringToArray(string("0000+00099"), A, MAX_DIGITS, n));
}
TEST_CASE("string is too long") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS];
   int n;
   CHECK_FALSE(fromStringToArray(string("11111111111111111111111111111111111111111111111111111111111111111111111111111111111"), A, MAX_DIGITS, n));
}
TEST_CASE("string is too small") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS];
   int n;
   CHECK(fromStringToArray(string("1"), A, MAX_DIGITS, n));
   int EXPECTED[MAX_DIGITS] = {1};
   CHECK(equalValues(A, EXPECTED, n, MAX_DIGITS));
}


//------------------------------------------------------------------------------
// starting tests for add
//------------------------------------------------------------------------------
TEST_CASE("first operand greater") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS] = {1, 2, 3, 4};
   int nA = 4;
   int B[MAX_DIGITS] = {5, 6, 7};
   int nB = 3;
   int C[MAX_DIGITS];
   int nC = MAX_DIGITS; // important, precondition
   CHECK(add(A, nA, B, nB, C, nC));
   int EXPECTED[MAX_DIGITS] = {6, 8, 0, 5};
   CHECK(equalValues(C, EXPECTED, nC, MAX_DIGITS));
}

TEST_CASE("second operand greater") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS] = {1, 2, 3, 4, 5, 6, 7, 8};
   int nA = 8;
   int B[MAX_DIGITS] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
   int nB = 13;
   int C[MAX_DIGITS];
   int nC = MAX_DIGITS; // important, precondition
   CHECK(add(A, nA, B, nB, C, nC));
   int EXPECTED[MAX_DIGITS] = {4, 5, 6, 7, 8, 9, 0, 2,4, 3, 3, 3, 3};
  CHECK(equalValues(C, EXPECTED, nC, MAX_DIGITS));
}

TEST_CASE("add carry 1") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS] = {8, 9};
   int nA = 2;
   int B[MAX_DIGITS] = {4};
   int nB = 1;
   int C[MAX_DIGITS];
   int nC = MAX_DIGITS; // important, precondition
   CHECK(add(A, nA, B, nB, C, nC));
   int EXPECTED[MAX_DIGITS] = {2, 0, 1};
   CHECK(equalValues(C, EXPECTED, nC, MAX_DIGITS));
}

TEST_CASE("all zeroes") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS] = {0,0};
   int nA = 2;
   int B[MAX_DIGITS] = {0};
   int nB = 1;
   int C[MAX_DIGITS];
   int nC = MAX_DIGITS; // important, precondition
   CHECK(add(A, nA, B, nB, C, nC));
   int EXPECTED[MAX_DIGITS] = {0};
   CHECK(equalValues(C, EXPECTED, nC, MAX_DIGITS));
}
TEST_CASE("add non zero with zero type array") {
   const int MAX_DIGITS = 72;
   int A[MAX_DIGITS] = {1,2,3,4,5,6,0,0};
   int nA = 8;
   int B[MAX_DIGITS] = {0};
   int nB = 1;
   int C[MAX_DIGITS];
   int nC = MAX_DIGITS; // important, precondition
   CHECK(add(A, nA, B, nB, C, nC));
   int EXPECTED[MAX_DIGITS] = {1,2,3,4,5,6,0,0};
   CHECK(equalValues(C, EXPECTED, nC, MAX_DIGITS));
}


// © 2022 Gladys Monagan 