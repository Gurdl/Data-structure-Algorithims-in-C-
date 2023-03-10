// Name:Gurdev singh
// CPSC 1160


#include <string>
#include <iostream>
#include "linkedlist.h"

using std::cout, std::endl, std::string;

void printPrompt() {
   cout << "\n--> ";
}

void printPrompt(string str) {
   printPrompt();
   cout << str;
}

int main() {
   Node *p, *q;
   p = cons(3, cons(2, nullptr));
   printPrompt();
   cout << p << endl; 
   cout << "\nexpecting [ 3 2 ]\n";

   p = append(1, p); 
   printPrompt(" after append: ");
   cout << p << endl;
   cout << "\nexpecting [ 3 2 1 ]\n";
      
   p = reverse(p);
   printPrompt("after reverse: ");
   cout << p << endl; 
   cout << "\nexpecting [ 1 2 3 ]\n";
      
   printPrompt();
   if (searchInOrder(3, p))
      cout << "found 3 as expected\n";
   else
      cout << "ERROR: did not find 3\n";
   
   printPrompt();
   if (searchInOrder(4, p))
      cout << "ERROR: found 4\n";
   else
      cout << "did not find 4 as expected\n";
      
   p = deleteList(p); 
   printPrompt("after deleteList: ");
   cout << p << endl;
   cout << "\nexpecting [ ]\n";
      
   p = cons(8, cons(7, cons(3, cons(1, cons(3, nullptr)))));
   printPrompt();
   cout << p << endl;
   cout << "\nexpecting p = [ 8 7 3 1 3 ]\n";

   q = cons(9, cons(8, cons(7, cons(3, cons(1, cons(3, cons(9, nullptr)))))));
   printPrompt();
   cout << q << endl;
   cout << "\nexpecting q = [ 9 8 7 3 1 3 9 ]\n";

   q = removeAll(9, q);
   printPrompt();
   cout << q << endl;
   cout << "\nexpecting q = [ 8 7 3 1 3 ]\n";

   printPrompt();      
   if (equal(q, p))
      cout << "q is equal to p as expected\n";
   else
      cout << "ERROR: p and q are equal but equal returned false\n";

   q = removeAll(3, q);
   printPrompt();
   cout << q << endl;
   cout << "\nexpecting q = [ 8 7 1 ]\n";
      
   printPrompt();      
   if (isLonger(p, q))
      cout << "p is longer than q as expected\n";
   else
      cout << "ERROR: p does have more elements than q\n";

   p = deleteList(p);
   printPrompt("after deleteList: ");
   cout << p << endl;
   cout << "\nexpecting [ ]\n";

   q = deleteList(q);
   printPrompt("after deleteList: ");
   cout << q << endl;
   cout << "\nexpecting [ ]\n";

   int A[4] = {1, 3, 5, 7};
   q = array2List(A, 4);
   printPrompt("after array2List: q = ");
   cout << q << endl;  
   cout << "\nexpecting q = [ 1 3 5 7 ]\n";

   q = deleteList(q);
   printPrompt("after deleteList: ");
   cout << q << endl;
   cout << "\nexpecting [ ]\n";
   
  
   return 0;
}

