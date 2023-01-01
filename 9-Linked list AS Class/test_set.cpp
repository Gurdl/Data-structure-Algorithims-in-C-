// Name:
// Student Number:

// Assignment #9, CpSc 1160
// Author: Gladys Monagan

#include <iostream>
#include <cstdlib>
#include "set.h"
#include "set_utils.h"
using std::cout, std::endl;

// uncomment if you do the bonus
// #define BONUS_DONE

// 19 should be inserted into the local copy
void test_copy_constructor_pass_by_value(Set a) {
   a.insert(19);
}

// make a set and return it
// the copy constructor is called
Set test_return_copy_constructor() {
   cout << "\nfunction that creates a set and returns it\n";
   Set a;
   a.insert(3);
   a.insert(2);
   a.insert(5);
   cout << "before exiting test_return_copy_constructor a = " << a << "\n";
   return a;
}

void test_destructor() {
   Set local;
   local.insert(1);
   local.insert(2);
   std::cout << "a local set has values " << local << "\n";
   // the destructor of local is called
}

void test_isEmpty_size(Set& s) {
   cout << "empty set: " <<  s << endl; 
   cout << "expecting:{ }\n";
   cout << "|s|=" << s.size() << endl;
   cout << "expecting:|s|= 0\n";
}

void test_insert_from_empty(Set& s) {   
   s.insert(3); s.insert(1); s.insert(9); s.insert(3); s.insert(7); s.insert(5);
   cout << "s = " << s << endl; 
   cout << "expecting:s = { 1 3 5 7 9 }\n";
}

void test_member(Set& s) {
   if (!s.member(2)) 
      cout << "2 is not in the set " << s << " as expected\n";
   else
      cout << "ERROR: 2 is in the set " << s << endl;
   if (s.member(7)) 
      cout << "7 is in the set " << s << " as expected\n";
   else
      cout << "ERROR: 7 is NOT in the set " << s << endl;
}

void test_size(Set& s) {
   cout << "|s|=" << s.size() << endl;
   cout << "expecting:|s|= 5\n";
}

void test_remove(Set& s) {
   s.remove(7); s.remove(1); s.remove(9); s.remove(10);
   cout << "\nafter the removals: s = " << s << endl; 
   cout << "expecting:s = { 3 5 }\n";
}

void test_insert(Set& s, Set& t) {
   s.insert(1); s.insert(7); s.insert(3);
   cout << "with insertions: s = " << s << endl;
   cout << "expecting:s = { 1 3 5 7 }\n";
   t.insert(3); t.insert(5); t.insert(4); 
   cout << "with insertions: t = "<< t << endl; 
   cout << "expecting:t = { 3 4 5 }\n";
}

void test_subset() {
   Set a;
   a.insert(3);
   Set b;
   b.insert(3);
   if (a < b)
      cout << a << " is a subset of " << b << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN a subset of " << b << endl;
   b.insert(5);
   if (a < b)
      cout << a << " is a subset of " << b << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN a subset of " << b << endl;
   if (a < a)
      cout << a << " is a subset of " << a << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN a subset of " << a << endl;
   cout << endl;
}

#ifdef BONUS_DONE
void test_equal() {
   Set a;
   Set b;
   if (a == b)
      cout << a << " is equal to " << b << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN equal to " << b << endl;
   b.insert(3);
   a.insert(3);
   if (a == b)
      cout << a << " is equal to " << b << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN equal to " << b << endl;
   b.insert(5);
   a.insert(5);
   if (a == b)
      cout << a << " is equal to " << b << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN equal to " << b << endl;
   if (a == a)
      cout << a << " is equal to " << a << " as expected" << endl;
   else
      cout << "ERROR " << a << "SHOULD HAVE BEEN equal to " << a << endl;
   cout << endl;
}



void test_proper_subset(Set& s, Set& t) {
   if (t < s)
      cout << "ERROR " << t << " is a proper subset of " << s << endl;
   else
      cout << "as expected, " << t << " is not a proper subset of " << s << endl;

   if (t < t)
      cout << "ERROR " << t << " is a proper subset of " << t << endl;
   else
      cout << "as expected, " << t << " is not a proper subset of " << t << endl;
   
   Set q;
   q.insert(3);
   if (q < s)
      cout << "as expected, " << q << " is a proper subset of " << s << endl;
   else
      cout << "ERROR " << q << " is not a a proper subset of " << s << endl;
}


#endif


int main() 
{
   {
   Set s, t;
   test_isEmpty_size(s);
   test_insert_from_empty(s);
   test_member(s);
   test_size(s);
   test_remove(s);
   test_insert(s, t);
   
   Set a = s + t;
   cout << s << " union " << t << " = " << a << endl;
   cout << "expecting:a = { 1 3 4 5 7 }\n";
   s.remove(3); 
   cout << "remove 3: s = " << s << endl;
   cout << "expecting:s = { 1 5 7 }\n";
   t.remove(4);
   cout << "remove 4: t = " << t << endl;
   cout << "expecting:t = { 3 5 }\n";
   
   s.insert(3); 
   cout << "insert 3: s = " << s << endl;
   cout << "expecting:s = { 1 3 5 7 }\n";
   t.insert(4);
   cout << "insert 4: t = " << t << endl;
   cout << "expecting:t = { 3 4 5 }\n";
   Set b = s * t;
   cout << s << " intersect " << t << " = " << b << endl;
   cout << "expecting:b = { 3 5 }\n";
   cout << "s = " << s << endl;
   cout << "expecting:s = { 1 3 5 7 }\n";
   cout << "t = " << t << endl;
   cout << "expecting:t = {3 4 5 }\n";
   
   test_destructor();

   Set q;
   q.insert(3);
   cout << "before q = " << q << endl;
   test_copy_constructor_pass_by_value(q);
   cout << "after q = " << q << " which is the same as before \n";
   
   Set r = test_return_copy_constructor();
   cout << "r = " << r << endl;
   
   // test_subset();
   //-----------------------------------------------------------------
   // BONUS
   //-----------------------------------------------------------------
   #ifdef BONUS_DONE
   test_proper_subset(s, t);
   test_equal();
   #endif
   return 0;
}
return 0;
}

//define sertuctor:



// copyright 2022 Gladys Monagan
