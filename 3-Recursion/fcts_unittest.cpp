// Name: Gurdev singh
//

// if you do the bonus, uncomment the next line
#define BONUS
/*
g++ -pedantic -Wall -Wextra  -std=c++17 fcts_unittest.cpp -o fcts_unittest
*/

/*
The tutorial
https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md

Reference
https://github.com/doctest/doctest/blob/master/doc/markdown/readme.md#reference

Macros
https://github.com/doctest/doctest/blob/master/doc/markdown/assertions.md
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// it is terrible programming style to #include an implementation cpp file    //
//      we are only doing this at the beginning of the course                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
#include "fcts.cpp"
using namespace std;
using std::string;
using std::stringstream;

//-----------------------------------------------------------------
// writeBackwardForward
// precondition: n > 0
//-----------------------------------------------------------------
TEST_CASE("writeBackwardForward")
{
   SUBCASE("1Digit") {
      std::stringstream ss;
      writeBackwardForward(7, ss);
      CHECK(ss.str() == "7\n7");
   }
   SUBCASE("2Digits") {
      std::stringstream ss;
      writeBackwardForward(12, ss);
      CHECK(ss.str() == "21\n12");
   }
   SUBCASE("6Digits") {
      std::stringstream ss;
      writeBackwardForward(123456, ss);
      CHECK(ss.str() == "654321\n123456");
   }
   SUBCASE("RepeatedDigits") {
      std::stringstream ss;
      writeBackwardForward(9999, ss);
      CHECK(ss.str() == "9999\n9999");
   }
   SUBCASE("EvenTrailingZeros") {
      std::stringstream ss;
      writeBackwardForward(10000, ss);
      CHECK(ss.str() == "00001\n10000");
   }
   SUBCASE("OddTrailingZeros") {
      std::stringstream ss;
      writeBackwardForward(9000, ss);
      CHECK(ss.str() == "0009\n9000");
   }
   SUBCASE("10SpecialCase") {
      std::stringstream ss;
      writeBackwardForward(10, ss);
      CHECK(ss.str() == "01\n10");
   }
   SUBCASE("100SpecialCase") {
      std::stringstream ss;
      writeBackwardForward(100, ss);
      CHECK(ss.str() == "001\n100");
   }
}

//-----------------------------------------------------------------
// smaller
// precondition:
//   1 <= n <= declared size of the array A
//-----------------------------------------------------------------
TEST_CASE("smaller")
{
   SUBCASE("All values are smaller than Given value")
   {
      int A[] = {1, 2, 3, 4, 5, 6};
      int n = 6;
      int x = 7;
      CHECK(smaller(x, A, n) == true);

   }
   SUBCASE(" values of array are larger than Given value")
   {
      int A[] = {1, 2, 3, 4, 5, 10};
      int n = 6;
      int x = 7;
      CHECK(smaller(x, A, n) == false);

   }
   SUBCASE(" values of array are same with X")
   {
      int A[] = {1,1,1,1,1,1};
      int n = 6;
      int x = 1;
      CHECK(smaller(x, A, n) == false);

   }

}

//-----------------------------------------------------------------
// maximum
// precondition:
//   1 <= n <= declared size of the array A
// I have purposely sometimes made n smaller than the declared size
// of the array and I have put a large number as the last element
// to test for "going out of range"
//-----------------------------------------------------------------

TEST_CASE("maximum")
 {
   SUBCASE("SpecialCaseOneElement") {
      int A[] = { 7, 100 };
      int n = 1;
      int max = 7;
      CHECK(maximum(A, n) == max);
   }
   SUBCASE("OddNumberMaxFirst") {
      int A[] = { -1, -2, -3, -4, -4, 100 };
      int n = 5;
      int max = -1;
      CHECK(maximum(A, n) == max);
   }
   SUBCASE("EvenNumberMaxLast") {
      int A[] = { 1, 2, 3, 4, 5, 6, 7 };
      int n = 6;
      int max = 6;
      CHECK(maximum(A, n) == max);
   }
   SUBCASE("EvenNumberMaxFirst") {
      int A[] = { 16, 2, 3, 4, 4, 4, 100 };
      int n = 6;
      int max = 16;
      CHECK(maximum(A, n) == max);
   }
   SUBCASE("OddNumberMiddle") {
      int A[] = { 1, 2, 100, 2, 1, 200 };
      int n = 5;
      int max = 100;
      CHECK(maximum(A, n) == max);
   }
   SUBCASE("Repeats") {
      int A[] = { 7, 7, 7, 7, 7, 100 };
      int n = 5;
      int max = 7;
      CHECK(maximum(A, n) == max);
   }
}

//-----------------------------------------------------------------
// isStrictlyDescendingTest
//-----------------------------------------------------------------
TEST_CASE("isStrictlyDescending") {
    SUBCASE("SpecialCase") {
      int A[] = { 11 };
      CHECK(isStrictlyDescending(A, 1));
    }
   SUBCASE("OneElement") {
      int A[] = { 11 };
      CHECK(isStrictlyDescending(A, 1));
   }
   SUBCASE("SmallFail") {
      int A[] = { 1, 2 };
      CHECK_FALSE(isStrictlyDescending(A, 2));
   }
   SUBCASE("SmallNotStrictlyDescendingFail") {
      int A[] = { 2, 2 };
      CHECK_FALSE(isStrictlyDescending(A, 2));
   }
   SUBCASE("SmallStrictlyDescending") {
      int A[] = { 2, 1 };
      CHECK(isStrictlyDescending(A, 2));
   }
   SUBCASE("Typical4") {
      int A[] = { 10, 9, 8, 7 };
      CHECK(isStrictlyDescending(A, 4));
   }
   SUBCASE("Typical4Size5") {
      int A[] = { 10, 9, 8, 7, 100 };
      CHECK(isStrictlyDescending(A, 4));
   }
   SUBCASE("Typical5") {
      int A[] = { 10, 9, 8, 7, 2 };
      CHECK(isStrictlyDescending(A, 5));
   }
   SUBCASE("Typical5Size6") {
      int A[] = { 10, 9, 8, 7, 2, 100 };
      CHECK(isStrictlyDescending(A, 5));
   }
   SUBCASE("OnlyDescendingOddNumberFail") {
      int A[] = { 10, 9, 9, 8, 7 };
      CHECK_FALSE(isStrictlyDescending(A, 5));
   }
   SUBCASE("OnlyDescendingOddFail") {
      int A[] = { 10, 9, 9, 8, 7, 100 };
      CHECK_FALSE(isStrictlyDescending(A, 5));
   }
   SUBCASE("OnlyDescendingEvenNumberFail") {
      int A[] = { 10, 10, 9, 8, 7, 2 };
      CHECK_FALSE(isStrictlyDescending(A, 6));
   }
   SUBCASE("OnlyDescendingEvenFail") {
      int A[] = { 10, 10, 9, 8, 7, 2, 100 };
      CHECK_FALSE(isStrictlyDescending(A, 6));
   }
   SUBCASE("Ascending") {
      int A[] = { 7, 8, 9, 10 };
      CHECK_FALSE(isStrictlyDescending(A, 4));
   }
   SUBCASE("EqualValues") {
      int A[] = { 1, 1, 1 };
      CHECK_FALSE(isStrictlyDescending(A, 3));
   }
}

//---------------------------------------------------------------------------//
// swapPairsLeftToRight
// precondition:
//   1 <= n <= declared size of the array A
//---------------------------------------------------------------------------//
// Determines if the 1st n elements of A are equal to the 1st m elements of B
// precondition:
//   A has been declared to have space for n integers
//   B has been declared to have space for m integers
// postcondition:
//   true if every A[i] is equal to every B[i], false otherwise
bool equalArrays(const int A[], int n, const int B[], int m)
{
   if (n != m) // different number of elements
      return false;
   for (int i = 0; i < n; i++)
      if (A[i] != B[i])
         return false;
   return true;
}

TEST_CASE("swapPairsLeftToRight")
{
   SUBCASE("OneElement") {
      int A[] = { 11 };
      int EXPECTED_A[] = { 11 };
      swapPairsLeftToRight(A, 1);
      CHECK(equalArrays(A, 1, EXPECTED_A, 1));
   }
   SUBCASE("EvenNumberOfElements2")
   {
      int A[] = {11, 22};
      int EXPECTED_A[] = {22, 11};
      swapPairsLeftToRight(A, 2);
      for (int i = 0; i < 2; i++)
      {
         cout << A[i];
      }
      CHECK(equalArrays(A, 2, EXPECTED_A, 2));
   }
   SUBCASE("OddNumberOfElements3")
   {
      int A[] = {11, -22, 33};
      int EXPECTED_A[] = {-22, 11, 33};
      swapPairsLeftToRight(A, 3);
      CHECK(equalArrays(A, 3, EXPECTED_A, 3));
   }
   SUBCASE("EvenNumberOfElements")
   {
      int A[] = {11, 22, 33, 44, 55, 66};
      int EXPECTED_A[] = {22, 11, 44, 33, 66, 55};
      swapPairsLeftToRight(A, 6);
      CHECK(equalArrays(A, 6, EXPECTED_A, 6));
   }
   SUBCASE("EvenNumberOfElementsPlus1")
   {
      int A[] = {11, 22, 33, 44, 55, 66, 77};
      int EXPECTED_A[] = {22, 11, 44, 33, 66, 55};
      swapPairsLeftToRight(A, 6);
      CHECK(equalArrays(A, 6, EXPECTED_A, 6));
   }
   SUBCASE("OddNumberOfElements")
   {
      int A[] = {11, 22, 33, 44, 55};
      int EXPECTED_A[] = {22, 11, 44, 33, 55};
      swapPairsLeftToRight(A, 5);
      CHECK(equalArrays(A, 5, EXPECTED_A, 5));
   }
   SUBCASE("OddNumberOfElementsPlus1")
   {
      int A[] = {11, 22, 33, 44, 55, 66};
      int EXPECTED_A[] = {22, 11, 44, 33, 55};
      swapPairsLeftToRight(A, 5);
      CHECK(equalArrays(A, 5, EXPECTED_A, 5));
   }
}

//---------------------------------------------------------------------------//
// goesFirst
//---------------------------------------------------------------------------//
TEST_CASE("goesFirst") {
   SUBCASE("BrderCaseOneCharDifferentCases") {
      CHECK(goesFirst("a", "A") == 0);
      CHECK(goesFirst("A", "a") == 0);
      CHECK(goesFirst("a", "a") == 0);
      CHECK(goesFirst("A", "A") == 0);
   }
   SUBCASE("BrderCaseOneCharDifferentCases") {
      CHECK(goesFirst("z", "Z") == 0);
      CHECK(goesFirst("Z", "z") == 0);
      CHECK(goesFirst("z", "z") == 0);
      CHECK(goesFirst("Z", "Z") == 0);
   }
   SUBCASE("Identical4") {
      CHECK(goesFirst("love", "love") == 0);
      CHECK(goesFirst("laughing", "Laughing") == 0);
   }
   SUBCASE("SameWithDifferentCases") {
      CHECK(goesFirst("SupercaliFragilisticExpialidocious",
      "supercalifragilisticexpialidocious") == 0);
   }
   SUBCASE("ShorterArgArg1Odd") {
      CHECK(goesFirst("fun", "funny") > 0);
   }
   SUBCASE("ShorterArgArg1Even") {
      CHECK(goesFirst("rat", "rattle") > 0);
   }
   SUBCASE("ShorterArgArg1OddFail") {
      CHECK(goesFirst("let", "ladder") < 0);
   }
   SUBCASE("ShorterArgArg1OddEven") {
      CHECK(goesFirst("bank", "background") < 0);
   }
   SUBCASE("SameLengthArg1First") {
      CHECK(goesFirst("Bear", "BeEr") > 0);
   }
   SUBCASE("SpecialEmptyArg1") {
      CHECK(goesFirst("", "empty") > 0);
   }
   // swap arguments
   SUBCASE("ShorterArgArg2OddFail") {
      CHECK(goesFirst("funny", "fun") < 0);
   }
   SUBCASE("ShorterArgArg2EvenFail") {
      CHECK(goesFirst("rattle", "rat") < 0);
   }
   SUBCASE("ShorterArgArg2Odd") {
      CHECK(goesFirst("ladder", "let") > 0);
   }
   SUBCASE("ShorterArgArg2Even") {
      CHECK(goesFirst("background", "bank") > 0);
   }
   SUBCASE("SameLengthArg2First") {
      CHECK(goesFirst("BeEr", "Bear") < 0);
   }
   SUBCASE("SpecialEmptyArg2") {
      CHECK(goesFirst("empty", "") < 0);
   }
}
//ifdef BONUS
//---------------------------------------------------------------------------//
// minPosNum
// precondition:
//   1 <= n <= declared size of the array A
//---------------------------------------------------------------------------//
TEST_CASE("minPosNumTest") {
   SUBCASE("NoElementsFail") {
      int A[] = { 3 };
      CHECK(minPosNum(A, 1) == 3);
   }
   
   SUBCASE("OneNegativeIntegerFail") {
      int A[] = { -7 };
      CHECK(minPosNum(A, 1) == 0);
   }
   SUBCASE("OnePositiveInteger") {
      int A[] = { 7 };
      CHECK(minPosNum(A, 1) == 7);
   }
   SUBCASE("OneZero") {
      int A[] = { 0 };
      CHECK(minPosNum(A, 1) == 0);
   }
   SUBCASE("MinimumPositiveFirstLength2") {
      int A[] = {1, 7};
      CHECK(minPosNum(A, 2) == 1);
      int B[] = {4, -8};
      CHECK(minPosNum(B, 2) == 4);
      int C[] = {4, 0};
      CHECK(minPosNum(C, 2) == 4);
   }
   SUBCASE("MinimumPositiveFirstLength3") {
      int A[] = {1, 7, 5};
      CHECK(minPosNum(A, 2) == 1);
      int B[] = {4, -8, -10};
      CHECK(minPosNum(B, 2) == 4);
      int C[] = {4, 0, 0};
      CHECK(minPosNum(C, 2) == 4);
   }
   SUBCASE("MinimumPositiveSecondLength2") {
      int A[] = {11, 7};
      CHECK(minPosNum(A, 2) == 7);
      int B[] = {-4, 8};
      CHECK(minPosNum(B, 2) == 8);
      int C[] = {0, 6};
      CHECK(minPosNum(C, 2) == 6);
   }
   SUBCASE("MinimumPositiveLast") {
      int A[] = {11, 7, 3};
      CHECK(minPosNum(A, 3) == 3);
      int B[] = {-4, -18, 3};
      CHECK(minPosNum(B, 3) == 3);
      int C[] = {0, 0, 6};
      CHECK(minPosNum(C, 3) == 6);
   }
   SUBCASE("WithRepeatsLast") {
      int A[] = {11, 7, 7, 3};
      CHECK(minPosNum(A, 4) == 3);
   }
   SUBCASE("WithRepeatsFirst") {
      int B[] = {1, 4, 4, 4};
      CHECK(minPosNum(B, 4) == 1);
   }
   SUBCASE("WithRepeatsFail") {
      int A[] = {-2, -2, -5};
      CHECK(minPosNum(A, 3) == 0);
      int B[] = {-2, -5, -1, -1, -1};
      CHECK(minPosNum(B, 5) == 0);
   }
   SUBCASE("PositiveMinimumSecondToLast") {
      int A[] = {-2, -5, 0, 1, -4};
      CHECK(minPosNum(A, 5) == 1);
      int B[] = {-2, -5, 3, 2, -1};
      CHECK(minPosNum(B, 5) == 2);
   }
}
//#endif

// © 2022 Gladys Monagan