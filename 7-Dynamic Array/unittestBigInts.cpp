// Name: Gladys Monagan
// Do not post anywhere

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream> // std::stringstream
#include <string>  // std::string
using namespace std;
#include "BigInts.h"

TEST_CASE("read and write")
 {
   SUBCASE("few digits")
    {
      stringstream ss_in("000123456789");
       BigInt* x= readBigInt(ss_in,10);
      stringstream ss_out;
      writeBigInt(ss_out,x);
      CHECK(ss_out.str() == "123456789");
      int value=numberOfDigits(x);
      CHECK_EQ(value, 9);
   }
   SUBCASE("one digit") {
      stringstream ss_in("7");
      BigInt* x = readBigInt(ss_in);
      CHECK_EQ(numberOfDigits(x), 1);
      stringstream ss_out;
      writeBigInt(ss_out, x);
      CHECK(ss_out.str() == "7");
   }

   SUBCASE("more digits") {
      stringstream ss_in("1234567891123456789123456789");
      BigInt* x = readBigInt(ss_in);
      CHECK_EQ(numberOfDigits(x), 28);
      stringstream ss_out;
      writeBigInt(ss_out, x);
      CHECK(ss_out.str() == "1234567891123456789123456789");
   }
   SUBCASE("no leading zeros") {
      stringstream ss_in("0000000000008765");
      BigInt* x = readBigInt(ss_in);
      CHECK_EQ(numberOfDigits(x), 4);
      stringstream ss_out;
      writeBigInt(ss_out, x);
      CHECK(ss_out.str() == "8765");
   }
}

TEST_CASE("add") {
   SUBCASE("few digits no carry") {
      stringstream ss_x("456");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("11");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = add(x, y);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "467");
      CHECK_EQ(numberOfDigits(z), 3);
   }

   SUBCASE("with carry") {
      stringstream ss_x("9999999999");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("11");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = add(x, y);
      CHECK_EQ(numberOfDigits(z), 11);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "10000000010");
   }
}

TEST_CASE("subtract cannot have a bigger second operand") {
   SUBCASE("large first operand small second operand") {
      stringstream ss_x("10000000000000000000000000000000000000");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("1111111");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = subtract(x, y);
      CHECK_EQ(numberOfDigits(z), 37);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "9999999999999999999999999999998888889");
   }

   SUBCASE("off by one") {
      stringstream ss_x("6789678967896789");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("6789678967896788");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = subtract(x, y);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK_EQ(numberOfDigits(z), 1);
      CHECK(ss_out.str() == "1");
   }
}

  TEST_CASE("constant 0") {
   SUBCASE("0") {
      stringstream ss_in("0");
      BigInt* x = zeroConstant();
      stringstream ss_out;
      writeBigInt(ss_out, x);
      CHECK(ss_out.str() == "0");
   }
   SUBCASE("subtract to get 0") {
      stringstream ss_x("12312312312312312312321312377777");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("12312312312312312312321312377777");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = subtract(x, y);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "0");
   }
   SUBCASE("add 0 + 0") {
      stringstream ss_x("0000000000");
      BigInt* x = readBigInt(ss_x);
      BigInt* y = zeroConstant();
      BigInt* z = add(x, y);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "0");
   }
   }
   TEST_CASE("mult") {
   SUBCASE("4 digit value with 2 digit")
   {
      stringstream ss_x("7590");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("13");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = multiply(x, y,10);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "98670");
   }
   SUBCASE("both of 2 digit")
   {
      stringstream ss_x("77");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("77");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = multiply(x, y,10);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "5929");
   }
    SUBCASE("both of 3 digit")
   {
      stringstream ss_x("11111");
      BigInt* x = readBigInt(ss_x);
      stringstream ss_y("11111");
      BigInt* y = readBigInt(ss_y);
      BigInt* z = multiply(x, y,10);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "123454321");
   }
}
TEST_CASE("addition in different bases") {
   SUBCASE("few digits in base 16")
    {
      stringstream ss_x("10A");
      BigInt* x = readBigInt(ss_x,16);
      stringstream ss_y("12B");
      BigInt* y = readBigInt(ss_y,16);
      BigInt* z = add(x, y,16);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "235");
      CHECK_EQ(numberOfDigits(z), 3);
   }
   SUBCASE("few digits in base 2")
    {
      stringstream ss_x("10000");
      BigInt* x = readBigInt(ss_x,2);
      stringstream ss_y("00001");
      BigInt* y = readBigInt(ss_y,2);
      BigInt* z = add(x, y,2);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "10001");
      CHECK_EQ(numberOfDigits(z), 5);
   }
}
TEST_CASE("subtraction in different bases")
{
   SUBCASE("few digits in base 16")
   {
      stringstream ss_x("155C");
      BigInt *x = readBigInt(ss_x, 16);
      stringstream ss_y("13A");
      BigInt *y = readBigInt(ss_y, 16);
      BigInt *z = subtract(x, y, 16);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "1422");
      CHECK_EQ(numberOfDigits(z), 4);
   }
   SUBCASE("few digits in base 2")
   {
      stringstream ss_x("1110101");
      BigInt *x = readBigInt(ss_x, 2);
      stringstream ss_y("101010");
      BigInt *y = readBigInt(ss_y, 2);
      BigInt *z = subtract(x, y, 2);
      stringstream ss_out;
      writeBigInt(ss_out, z);
      CHECK(ss_out.str() == "1001011");
      CHECK_EQ(numberOfDigits(z), 7);
   }
}

// © 2022 Gladys Monagan
