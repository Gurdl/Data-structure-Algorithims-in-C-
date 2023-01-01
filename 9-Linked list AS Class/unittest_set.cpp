// CPSC 1160 
// Author: Gladys Monagan
// Do not post anywhere.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>  // std::stringstream
#include <iostream>
#include <string> 
#include "set.h"
#include "set_utils.h"
using namespace std;
// uncomment if you do the bonus
 #define BONUS_DONE

using monagan::operator >>;
using std::stringstream, std::string;

TEST_CASE("constructors") {
   SUBCASE("no-arg constructor") {
      Set set;
      stringstream ss;
      ss << set;
      CHECK(ss.str() == "{ }");
   }
}

//depends on insert and remove
TEST_CASE("isEmpty") {
   Set set;
   CHECK(set.isEmpty());
   set.insert(1);
   cout<<"list:"<<endl;
   cout<<set;
   CHECK_FALSE(set.isEmpty());
   set.insert(9);
   CHECK_FALSE(set.isEmpty());
   set.remove(1);
   CHECK_FALSE(set.isEmpty());
   set.remove(9);
   CHECK(set.isEmpty());
   set.remove(99999);
   CHECK(set.isEmpty());
 }

TEST_CASE("insert") {
   Set set;
   SUBCASE("one element") {
      set.insert(7);
      stringstream ss;
      ss << set;
      CHECK(ss.str() == "{ 7 }");
   }
   stringstream ss_in("9 5 3");
   ss_in >> set;
   stringstream ss_out;
   ss_out << set;
   CHECK(ss_out.str() == "{ 3 5 7 9 }");
}

//depends on insert
TEST_CASE("size") {
   Set set;
   SUBCASE("no elements") {
      stringstream ss_out;
      ss_out << set;
      CHECK(ss_out.str() == "{ }");
   }
   set.insert(-7);
   SUBCASE("one element") {
      stringstream ss_out;
      ss_out << set;
      CHECK(ss_out.str() == "{ -7 }");
   }
   int n = 127;
   for (int i = 1; i < n; i++) {
      CHECK_EQ(set.size(), i);
      set.insert(i);
   }
}

TEST_CASE("member") {
   Set set;
   SUBCASE("no elements") {
      CHECK_FALSE(set.member(3));
   }
   stringstream ss_in("0 8 5 1 0 8 0");
   ss_in >> set;
   CHECK(set.member(0));
   CHECK(set.member(8));
   CHECK(set.member(5));
   CHECK(set.member(1));
   SUBCASE("greater element fail") {
      CHECK_FALSE(set.member(9));
   }
   SUBCASE("smaller element fail") {
      CHECK_FALSE(set.member(-4));
   }
}

TEST_CASE("remove") {
   SUBCASE("from an empty set") {
      Set set;
      set.remove(4);
      stringstream ss_out;
      ss_out << set;
      CHECK(ss_out.str() == "{ }");
   }
   SUBCASE("one element") {
      Set set;
      stringstream ss_in("7 5 3");
      ss_in >> set;
      set.remove(5);
      stringstream ss_out;
      ss_out << set;
      CHECK(ss_out.str() == "{ 3 7 }");
   }
   SUBCASE("at the head") {
      Set set;
      stringstream ss_in("0 8 5 1 0 8 0");
      ss_in >> set;
      set.remove(0);
      stringstream ss_out;
      ss_out << set;
      CHECK(ss_out.str() == "{ 1 5 8 }");
   }
}
TEST_CASE("copy constructor ") {
   SUBCASE("copy null") 
   {

      Set s;
      Set t(s);
      stringstream ss_out;
      ss_out << t;
       CHECK(ss_out.str() == "{ }");
   }
}
TEST_CASE("Assignemnt ") {
   SUBCASE("no elements") 
   {
      Set s,t;
      stringstream ss_in("0 8 5 1 0 8 0");
      ss_in >> s;
      s=t;
      stringstream ss_out;
      ss_out << s;
      CHECK(ss_out.str() == "{ }");
   }
   SUBCASE("changig elements") 
   {
      Set s,t;
      stringstream ss_in("0 8 5 1 0 8 0");
      ss_in >> s;
      stringstream ss_in2("1 2 3");
      ss_in2 >> t;
      s=t;
      stringstream ss_out;
      ss_out << s;
      CHECK(ss_out.str() == "{ 1 2 3 }");
      
   }
   
}
 TEST_CASE("union operator +") {
   Set s, t;
   s.insert(4);
   stringstream ss_in("1 7 5 3");
    ss_in >> t;
    stringstream ss_out;
    ss_out << (s + t);
   CHECK(ss_out.str() == "{ 1 3 4 5 7 }");
   SUBCASE("union with an empty list")
   {
      Set t;
      stringstream ss_in("1 7 5 3");
     ss_in >> t;
      Set empty;
      stringstream ss_out;
      ss_out << (t + empty);
      CHECK(ss_out.str() == "{ 1 3 5 7 }");
    }
   SUBCASE("union with an empty list") {
      Set empty;
      stringstream ss_out;
      ss_out << (empty + t);
      CHECK(ss_out.str() == "{ 1 3 5 7 }");
   }
   SUBCASE("first is longer")
   {
      Set t;
      stringstream ss_in("1 7 4 5 6 8 9 ");
     ss_in >> t;
      Set s;
      stringstream ss_in2("0 1 2 1");
      ss_in2>>s;
      stringstream ss_out;
      ss_out << (t + s);
      CHECK(ss_out.str() == "{ 0 1 2 4 5 6 7 8 9 }");
    }
 }

TEST_CASE("intersection operator *") {
   Set s, t;
   stringstream ss_in_s("1 4 6 7 18 9");
   ss_in_s >> s;
   stringstream ss_in_t("1 4 5 7 8 9");
   ss_in_t >> t;
   stringstream ss_out;
   ss_out << (s * t);
   CHECK(ss_out.str() == "{ 1 4 7 9 }");
   SUBCASE("intersection with an empty list") {
      Set empty;
      stringstream ss_out;
      ss_out << (t * empty);
      CHECK(ss_out.str() == "{ }");
   }
   SUBCASE("union with an empty list") {
      Set empty;
      stringstream ss_out;
      ss_out << (empty * t);
      CHECK(ss_out.str() == "{ }");
   }
}

TEST_CASE("subset operator <") {
   Set s, t;
   SUBCASE("both sets are empty") {
      CHECK(s < t);
   }
   stringstream ss_in("7 5 3");
   ss_in >> t;
   s.insert(7);
   CHECK(s < t);
   s.insert(3);
   CHECK(s < t);
   s.insert(5);
   SUBCASE("both sets are the same") {
      CHECK(s < t);
   }
   SUBCASE("s has more elements than t") {
      s.insert(9);
      CHECK_FALSE(s < t);
      s.insert(11);
      CHECK_FALSE(s < t);
   }
   SUBCASE("s has more elements than t") {
     Set s,t;
     stringstream ss_in("1 2 3 4 6 9");
      ss_in >> s;
      stringstream ss_in2("1 2 3 4 5 6");
      ss_in2 >> t;
      CHECK_FALSE(t < s);
      CHECK(t < t);

   }
   SUBCASE("middle element is different") {
     Set s,t;
     stringstream ss_in("1 2 6 9");
      ss_in >> s;
      stringstream ss_in2("1 3 6 9");
      ss_in2 >> t;
      CHECK_FALSE(t < s);
      CHECK(t < t);

   }
}


//-----------------------------------------------------------------
// BONUS
//-----------------------------------------------------------------

#ifdef BONUS_DONE
TEST_CASE("equal") {
   Set s, t;
   SUBCASE("empty sets") {
      CHECK(s == t);
   }
   s.insert(3);
   t.insert(5);
   SUBCASE("one element fail") {
      CHECK_FALSE(s == t);
   }
   t.insert(3);
   s.insert(5);
   SUBCASE("two elements") {
      CHECK(s == t);
   }
   t.remove(3);
   s.remove(5);
   SUBCASE("one different element fail") {
      CHECK_FALSE(s == t);
   }
   t.remove(5);
   s.remove(3);
   SUBCASE("two elements") {
      CHECK(s == t);
   }
   SUBCASE("empty again") {
      CHECK(s == t);
   }
}

TEST_CASE("proper subset")
 {
   Set s, t;
   SUBCASE("both sets are empty") {
      CHECK_FALSE(s % t);
   }
   stringstream ss_in("7 5 3");
   ss_in >> t;
   s.insert(7);
   CHECK(s % t);
   s.insert(3);
   CHECK(s % t);
   s.insert(5);
   SUBCASE("both sets are the same") {
      CHECK_FALSE(s % t);
   }
   s.insert(9);
   CHECK_FALSE(s % t);
   CHECK(t % s); // swapped operands
   s.insert(11);
   CHECK_FALSE(s % t); 
   CHECK(t % s);  // swapped operands
}
#endif

// copyright 2022 Gladys Monagan

