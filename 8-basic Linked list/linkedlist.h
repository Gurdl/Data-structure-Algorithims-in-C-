// CPSC 1160
// developed by Gladys Monagan
// do not post anywhere, do not modify

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

// main data structure
struct Node {
   int value; 
   Node *link; 
};

//returns the data field of the Node
// if p is the nullptr, we cannot get its data ...exit abruptly
int first(Node* p); 

// returns the link field of the Node
// if p is the nullptr, we cannot get its link.... exit abruptly
Node* rest(Node* p);

// change the value field (the first) of the Node pointed to by p
void setfirst(Node* p, int x);

// change the link field (the rest) of the Node pointed to by p
void setrest(Node* p, Node* q);

// construct a new node: allocate memory for a Node
// set x to be the field of the value and p to be the field of link
Node * cons( int x, Node* p);
void setNull(Node* p);
// reverse the list p doing  a "destructive" reverse 
// i.e. the pointers are rearranged, a new list is not created
// postcondition: 
//   return a pointer to the beginning of the reversed list
Node* reverse(Node *p);
void reverseInSecondNode(Node* p,Node* &newReverseNode);

// read integers input until the stream enters a fail state (e.g. end-of-file)
// of a non-digit character is entered
// i.e. stop by entering a letter (this causes the stream in: to fail)
// consume the character typed and reset the stream in to read again
std::istream& operator >> (std::istream& in, Node* & p);

// output p so that it looks like e.g. for values in p of 7 10 9
//   [ 7 10 9 ] namely an integer followed by a blank
// the empty list is printed as [ ] i.e. '[' followed by ' ' followed by ' ']'
std::ostream& operator << (std::ostream& out, Node* p);

// return a copy of p, so, a totally new list, independent of p
// the nodes in the copy are in the same order as in p
Node* copy(Node *p);

// create a new node with x in it and appends this node to the end of the list p
// precondition: 
//    the linear linked list p has been properly constructed
// postcondition: 
//    return a pointer to the beginning of the list
Node* append(int x, Node *p);

// determine if x is in the list p
// precondition: 
//    the linear linked list p has been properly constructed 
//    and is sorted in ascending order
// postcondition: 
//    return true if x is in p, false otherwise
bool searchInOrder(int x, Node *p);

// determine if the list p has duplicates
// precondition: 
//    the linear linked list p has been properly constructed
// postcondition: 
//    return true if p has elements (items) that appear more than once
bool hasDuplicates(Node *p);
//This function is a kind of helper that is used to check
//if the lements in linkes list are repeated:
bool checkDulpicates(int x,Node* p);

// given two lists, determine if the first list p is longer than
// the second list q without calling the function length
bool isLonger(Node *p, Node *q);

// return true if all the elements of p and q are equal:
//    in the same position and with the same values
//    both lists need to be of the same length
//    either p, q or both could be empty
bool equal( Node *p, Node *q);

// return a new list with every element appearing twice in the same order as p
// p is not modified
// postcondition: 
//    return a list that is independent of the original list p
Node* makeDuplicates(Node *p);

// delete every node of the list p returning memory to the heap
// precondition: 
//    the linear linked list p has been properly constructed
// postcondition: 
//    return the nullptr pointer once all the nodes have been deleted
Node * deleteList(Node *p);

// copy the n elements in the array into a linked list
// precondition: 
//    A has been allocated memory for at least n integers
// postcondition: 
//    return a pointer to the beginning of the list
Node * array2List(int A[], int n);

// merge p and q making a copy of all the elements  
// i.e. the returned list is independent of p and q
// precondition:
//    p and q are sorted in ascending order
// postcondition:
//    return a merged list with all the elements sorted in ascending order
Node* mergeTwoOrderedLists(Node* p, Node* q);

// remove every occurrence of x in p
// postcondition:
//    return a list without any x’s
Node* removeAll(int x, Node* p);
Node *del(Node *prev);

#endif

// copyright 2022 Gladys Monagan

