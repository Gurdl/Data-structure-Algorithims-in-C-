// Name:
// Student Number:

#ifndef SET_H
#define SET_H

#include <iostream>

class Set {
   public:
      // construct the empty Set
      Set(); 
      // return true if the Set is empty, false otherwise
      bool isEmpty() const; 
      // return the number of elements in the Set
      int size() const; 
      // return true if x is in the Set, false otherwise
      bool member(int x) const; 
      // insert x into the right place of the Set (in ascending order)
      // (if x is already in the Set, do nothing)
      void insert(int x); 
      // delete x from the Set (if x is not in the Set, do nothing)
      void remove(int x);  
          
      // return the union of a and b
      friend const Set operator +(const Set & a, const Set & b); 
      // return the intersection of a and b
      friend const Set operator *(const Set & a, const Set & b); 
      // return true if a is a subset of b
      friend bool operator < (const Set & a, const Set & b); 
      // output a set in the form { element0 element 1  ... elementn-1 }
      friend std::ostream& operator<< (std::ostream&, const Set&);
      // copy constructor
      // precondition: there will be enough heap memory
      Set(const Set&); 
      // overloaded assignment operator so that one set can be 
      // assigned to another
      // precondition: there will be enough heap memory
      Set& operator = (const Set& rtSide); 
      // destructor 
      // CPSC 1160 implementation detail: 
      // return all memory belonging the linked list 
      ~Set(); 

      // BONUS question
      // return true if it's a proper subset of other
      friend bool operator % (const Set & a, const Set & b); 
      // return true a and b are equal
      friend bool operator == (const Set & a, const Set & b); 
      
   private:
      struct Node {
         int value;
         Node * next;
      };
      // CPSC 1160 implementation details:
      // The linked list is sorted in ascending order so that the Set operations
      // union, intersect and subset can be done in linear time using merging. 
      // The insert operation needs to insert in order and if x is already 
      // there, it doesn't do anything.
      // So the list is always sorted and never has duplicates.
      Node * list;
      
      // constructor that takes p and sets the list to p
      // no copies of the nodes in p are made
      // CPSC 1160 suggested constructor, does not have to be implemented
      /*
      Set(Node* p);
      */

      // make a new node with the value x and the link set to p
      // return a pointer to the new node
      // we want to access cons in friend functions so make it static
      static Node * cons( int x, Node * p );
      // return the length of the linked list pointed to by p
      // CPSC 1160: make this function RECURIVE
      static int length(Node * p);
   
      // determine if x is in p
      // precondition: p is in ascending order
      static bool member(int x, Node * p);
      
      // insert x if not in p already
      // precondition: p is in ascending order
      // CPSC 1160: make this function RECURSIVE
      static Node* insert(int x, Node* p);

      // copy original list and return a new list (in the same order)
      static Node * copyList(Node *p); 

      // delete every node of the list (return memory to the heap)
      // return nullptr
      static Node * deleteList(Node *);

      // reverse in linear time the list pointed to by p
      // the reverse is destructive 
      static Node * reverse(Node * p);
    
    static Node* mergedList(Node* a, Node* b);


};

#endif

// copyright 2022 Gladys Monagan

