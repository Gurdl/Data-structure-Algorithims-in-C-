// Author: Gladys Monagan
// CPSC 1160
// Do not post anywhere.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
to run only the test cases makeDuplicates

on Windows
dtest_ll -tc=makeDuplicates


on Linux (MacOS)
./dtest_ll -tc=makeDuplicates

to exclude the array2List test cases (see the minus)

on Windows
dtest_ll -tce=array2List


on Linux (MacOS)
./dtest_ll  -tce=array2List
*/
#include <sstream>  // std::stringstream
#include <iostream>
#include <string>   // std::string
using std::stringstream, std::string;

#include "linkedlist.h"

TEST_CASE("output operator >>") {
   SUBCASE("empty list") {
      Node* p = nullptr;
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ ]");
   }

   
   SUBCASE("one element") {
      Node* p = cons(2021, nullptr);
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 2021 ]");
   }
   SUBCASE("3 elements") {
      Node* p = cons(7, cons(10, cons(9, nullptr)));
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 7 10 9 ]");
   }
   SUBCASE("more elements") {
      Node * p = cons(1, cons(2, cons(3, cons(4, cons(5, cons(6, nullptr))))));
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 1 2 3 4 5 6 ]");
   }
}

TEST_CASE("reverse") {
   SUBCASE("empty list") {
      Node* p = nullptr;
      stringstream actual;
      actual << reverse(p);
      CHECK(actual.str() == "[ ]");
   }
   SUBCASE("one element") {
      Node* p = cons(2020, nullptr);
      stringstream actual;
      actual << reverse(p);
      CHECK(actual.str() == "[ 2020 ]");
   }
   SUBCASE("3 elements") {
      Node* p = cons(7, cons(10, cons(9, nullptr)));
      stringstream actual;
      actual << reverse(p);
      CHECK(actual.str() == "[ 9 10 7 ]");
   }
   SUBCASE("4 elements") {
      Node* p = cons(0, cons(1, cons(2, cons(3, nullptr))));
      stringstream actual;
      actual << reverse(p);
      CHECK(actual.str() == "[ 3 2 1 0 ]");
   }
   SUBCASE("more elements") {
      Node * p = cons(0, cons(2, cons(-1, cons(1, cons(0, nullptr)))));
      stringstream actual;
      actual << reverse(p);
      CHECK(actual.str() == "[ 0 1 -1 2 0 ]");
   }
}

TEST_CASE("input operator << ") {
   SUBCASE("empty list") {
      Node *p;
      stringstream ss_in("k");
      ss_in >> p;
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ ]");
   }
   SUBCASE("one element") {
      Node* p ;
      stringstream ss_in("  2021   \n");
      ss_in >> p;
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 2021 ]");
   }
   SUBCASE("one element followed by a character") {
      Node* p;
      stringstream ss_in("  2022   k");
      ss_in >> p;
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 2022 ]");
   }
   SUBCASE("free formatted input") {
      Node *p;
      stringstream ss_in("13 14     15 16 17 18\n    19");
      ss_in >> p;
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 13 14 15 16 17 18 19 ]");
   }
   SUBCASE("free formatted input followed by a character") {
      Node* p;
      stringstream ss_in("13 14     15 16 17 18\n    19  k");
      ss_in >> p;
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 13 14 15 16 17 18 19 ]");
   }
}


TEST_CASE("copy") {
   SUBCASE("empty lists") {
      CHECK_EQ(copy(nullptr), nullptr);
   }
   SUBCASE("one empty list") {
      Node* p = cons(2021, nullptr);
      stringstream actual;
      actual << copy(p);
      CHECK(actual.str() == "[ 2021 ]");
   }
   SUBCASE("3 elements") {
      Node* p = cons(7, cons(10, cons(9, nullptr)));
      stringstream actual;
      actual << copy(p);
      CHECK(actual.str() == "[ 7 10 9 ]");
   }
   SUBCASE("4 elements") {
      Node* p = cons(0, cons(1, cons(2, cons(3, cons(4, nullptr)))));
      stringstream actual;
      actual << copy(p);
      CHECK(actual.str() == "[ 0 1 2 3 4 ]");
   }
   SUBCASE("more elements") {
      Node * p = cons(0, cons(2, cons(-1, cons(1, cons(0, nullptr)))));
      stringstream actual;
      actual << copy(p);
      CHECK(actual.str() == "[ 0 2 -1 1 0 ]");
   }
   SUBCASE("remove element from original") {
      Node * p = cons(0, cons(2, cons(-1, cons(1, cons(0, nullptr)))));
      stringstream p_ss, q_ss, qc_ss;
      Node* q = copy(p);
      qc_ss << q;
      CHECK(qc_ss.str() == "[ 0 2 -1 1 0 ]");
      Node* r = p;
      while (rest(rest(r)) != nullptr) r = rest(r);
      Node* discard = rest(r);
      setrest(r, nullptr);
      delete discard;
      p_ss << p;
      CHECK(p_ss.str() == "[ 0 2 -1 1 ]");
      q_ss << q;
      CHECK(q_ss.str() == "[ 0 2 -1 1 0 ]");
   }
   SUBCASE("remove element from copy") {
      Node * p = cons(0, cons(2, cons(-1, cons(1, cons(0, nullptr)))));
      stringstream p_ss, q_ss, qc_ss;
      Node* q = copy(p);
      qc_ss << q;
      CHECK(qc_ss.str() == "[ 0 2 -1 1 0 ]");
      Node* r = q;
      while (rest(rest(r)) != nullptr) r = rest(r);
      Node* discard = rest(r);
      setrest(r, nullptr);
      delete discard;
      p_ss << p;
      CHECK(p_ss.str() == "[ 0 2 -1 1 0 ]");
      q_ss << q;
      CHECK(q_ss.str() == "[ 0 2 -1 1 ]");
   }
}

TEST_CASE("append") {
   SUBCASE("from an empty list") {
      Node* p = nullptr;
      p = append(77, p);
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 77 ]");
   }
   SUBCASE("from a one element list") {
      Node* p = cons(88, nullptr);
      p = append(-1, p);
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 88 -1 ]");
   }
   SUBCASE("longer list") {
      Node * p = cons(0, cons(2, cons(-1, cons(1, cons(0, nullptr)))));
      p = append(-1, p);
      stringstream actual;
      actual << p;
      CHECK(actual.str() == "[ 0 2 -1 1 0 -1 ]");
   }
}

TEST_CASE("searchInOrder") {
   SUBCASE("empty") {
      CHECK_FALSE( searchInOrder(3, nullptr));
   }
   SUBCASE("one element") {
      Node* p = cons(4, nullptr);
      CHECK( searchInOrder(4, p) );
      CHECK_FALSE( searchInOrder(-5, p) );
   }
   SUBCASE("last element") {
      Node* p = cons(4, cons(5, cons(10, cons(11, nullptr))));
      CHECK( searchInOrder(11, p) );
      CHECK_FALSE( searchInOrder(6, p) );
   }
}

TEST_CASE("hasDuplicates") {
   SUBCASE("empty") {
      CHECK_FALSE( hasDuplicates(nullptr));
   }
   SUBCASE("odd number of repeats") {
      Node *p = cons(7, cons(7, cons(7, nullptr)));
      CHECK( hasDuplicates(p) );
   }
   SUBCASE("sprinkled repeats") {
      Node *p = cons(9, cons(7, cons(2, cons(5, cons(7, nullptr)))));
      CHECK( hasDuplicates(p) );
   }
}

TEST_CASE("isLonger") {
   SUBCASE("first longer than emptylist") {
      Node *p = cons(1, cons(3, cons(4, cons(5, nullptr))));
      CHECK( isLonger(p, nullptr) );
   }
   SUBCASE("first longer than second") {
      Node *p = cons(1, cons(3, cons(4, cons(5, nullptr))));
      Node *q = cons(8, nullptr);
      CHECK( isLonger(p, q) );
   }
   SUBCASE("not longer") {
      Node *p = cons(1, cons(3, cons(4, cons(5, nullptr))));
      Node *q = cons(1, cons(3, cons(4, cons(5, nullptr))));
      CHECK_FALSE( isLonger(p, q) );
   }
}

TEST_CASE("equal") {
   SUBCASE("empty lists") {
      CHECK( equal(nullptr, nullptr) );
   }
   SUBCASE("one empty list") {
      Node* p = nullptr;
      Node* q = cons(4, nullptr);
      CHECK_FALSE( equal(p, q) );
      CHECK_FALSE( equal(q, p) );
   }
   SUBCASE("left longer list") {
      Node* left =  cons(0, cons(1, cons(5, cons(7, nullptr))));
      Node* right = cons(0, cons(1, cons(5, nullptr)));
      CHECK_FALSE( equal(left, right) );
   }
   SUBCASE("right longer list") {
      Node* left =  cons(10, cons(11, cons(15, nullptr)));
      Node* right = cons(10, cons(11, cons(15, cons(17, nullptr))));
      CHECK_FALSE( equal(left, right) );
   }
}

TEST_CASE("makeDuplicates") {
   SUBCASE("empty lists") {
      CHECK( equal(nullptr, nullptr) );
   }
   SUBCASE("one element") {
      Node* p = cons(-1, nullptr);
      stringstream actual;
      actual << makeDuplicates(p);
      CHECK(actual.str() == "[ -1 -1 ]");
   }
   SUBCASE("odd number of elements in list") {
      Node *p = cons(-3, cons(-2, cons(-1, nullptr)));
      stringstream actual;
      actual << makeDuplicates(p);
      CHECK(actual.str() == "[ -3 -3 -2 -2 -1 -1 ]");
   }
   SUBCASE("typical") {
      Node *p = cons(0, cons(1, cons(2, cons(3, nullptr))));
      stringstream actual;
      actual << makeDuplicates(p);
      CHECK(actual.str() == "[ 0 0 1 1 2 2 3 3 ]");
   }
}
TEST_CASE("delete linked list") {
   SUBCASE("empty lists") {
      CHECK( equal(nullptr, nullptr) );
   }
   SUBCASE("one element") {
      Node* p = cons(-1, nullptr);
      stringstream actual;
      actual << deleteList(p);
      CHECK(actual.str() == "[ ]");
   }
   SUBCASE("have many element") {
      Node* p =cons(7,cons(11,cons(10,cons(-1, nullptr))));
      stringstream actual;
      actual << deleteList(p);
      CHECK(actual.str() == "[ ]");
   }
   }

TEST_CASE("array2List") {
   SUBCASE("typical") {
      int A[4] = {1, 3, 5, 7};
      Node* q = array2List(A, 4);
      stringstream actual;
      actual << q;
      CHECK(actual.str() == "[ 1 3 5 7 ]");
   }
   SUBCASE("empty array") {
      int A[1] = { 7};
      int n = 0;
      Node* q = array2List(A, n);
      stringstream actual;
      actual << q;
      CHECK(actual.str() == "[ ]");
   }
}

TEST_CASE("mergeTwoOrderedLists") {
   SUBCASE("first longer") {
      Node* p =  cons(1, cons(3, cons(5, cons(7, cons(8, cons(9, nullptr))))));
      Node* q = cons(2, cons(4, cons(6, nullptr)));
      stringstream actual;
      actual << mergeTwoOrderedLists(p, q);
      CHECK(actual.str() == "[ 1 2 3 4 5 6 7 8 9 ]");
   }
   SUBCASE("second longer") {
      Node* p =  cons(0, cons(1, cons(5, cons(7, nullptr))));
      Node* q = cons(0, cons(1, cons(5, nullptr)));
      stringstream actual;
      actual << mergeTwoOrderedLists(q, p);
      CHECK(actual.str() == "[ 0 0 1 1 5 5 7 ]");
   }
   SUBCASE("second empty") {
      Node* p =  cons(0, cons(1, cons(5, cons(7, nullptr))));
      Node* q = nullptr;
      stringstream actual;
      actual << mergeTwoOrderedLists(p, q);
      CHECK(actual.str() == "[ 0 1 5 7 ]");
   }
   SUBCASE("first empty") {
      Node* p =  nullptr;
      Node* q = cons(0, cons(1, cons(5, cons(7, nullptr))));
      stringstream actual;
      actual << mergeTwoOrderedLists(p, q);
      CHECK(actual.str() == "[ 0 1 5 7 ]");
   }
}

TEST_CASE("removeAll") {
   SUBCASE("first element") {
      Node* p =  cons(0, cons(1, cons(5, cons(6, nullptr))));
      stringstream actual;
      actual << removeAll(0, p);
      CHECK(actual.str() == "[ 1 5 6 ]");
   }
   SUBCASE("last elements") {
      Node* p =  cons(0, cons(1, cons(5, cons(7, cons(0, nullptr)))));
      stringstream actual;
      actual << removeAll(0, p);
      CHECK(actual.str() == "[ 1 5 7 ]");
   }
   SUBCASE("not in list") {
      Node *p = cons(9, cons(7, cons(2, cons(5, cons(7, nullptr)))));
      stringstream actual;
      actual << removeAll(-8, p);
      CHECK(actual.str() == "[ 9 7 2 5 7 ]");
   }
   SUBCASE("sprinkled repeats") {
      Node *p = cons(9, cons(7, cons(2, cons(5, cons(7, nullptr)))));
      stringstream actual;
      actual << removeAll(7, p);
      CHECK(actual.str() == "[ 9 2 5 ]");
   }
}

// copyright 2022 Gladys Monagan

