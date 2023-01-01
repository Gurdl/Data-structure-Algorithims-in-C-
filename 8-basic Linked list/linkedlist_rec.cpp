// Name:Gurdev singh
// Student number: 100376466
// RECURSIVE VERSION

// CPSC 1160, Assignment #8
// started by Gladys Monagan
// Do not post anywhere
// Fill in the missing code and submit with Brightspace

#include "linkedlist.h"
#include <cassert>
#include <string>
#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for cin
#include <ios>    // for declaration of 'streamsize' for cin


//returns the data field of the Node
// if p is the nullptr, we cannot get its data ...exit abruptly
int first(Node* p) { 
   assert(p != nullptr);
   return(p->value); 
}

// returns the link field of the Node
// if p is the nullptr, we cannot get its link.... exit abruptly
Node* rest(Node* p) { 
   assert(p != nullptr); 
   return(p->link); 
}

// change the value field (the first) of the Node pointed to by p
void setfirst(Node* p, int x) { 
   assert(p != nullptr); 
   p->value = x; 
}

// change the link field (the rest) of the Node pointed to by p
void setrest(Node* p, Node* q) { 
   assert(p != nullptr); 
   p->link = q; 
}

// construct a new node (allocate dynamic memory that goes on the heap) 
Node * cons( int x, Node* p) {
   Node* q = new Node;
   setfirst(q, x);
   setrest(q, p);
   return q;
}
//-----------------------------------------------------------------
// enter your code below 
// This is used to take the value and store into linked list
std::istream &operator>>(std::istream &in, Node *&p)
{
   int x;
   p = nullptr;
   while (in >> x)
   {
      p = cons(x, p);
   }
   // reset the  input stream mens clear the buffer fromunrequired datat
   in.clear();
   // consume the char at end of the line:
   // in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   in.ignore(std::numeric_limits<std::streamsize>::max());
   p = reverse(p);
   return in;
}
// This function is used to print the linked list:
std::ostream &operator<<(std::ostream &out, Node *p)
{
   if (p == nullptr)
   {
      out << "[ ]";
      return out;
   }
   out << "[ ";
   while (p != nullptr)
   {
      out << first(p) << " ";
      p = rest(p);
   }
   out << "]";
   return out;
}
// This function is used to reverse the linked list:
Node *reverse(Node *head)
{
   Node *p = head;
   if (p == nullptr || rest(p) == nullptr)
   {
      return p;
   }

   Node *prev = p;
   Node *curr = rest(p);
   while (curr != nullptr)
   {
      Node *next = rest(curr);
      setrest(curr, prev);
      // Update the pointers to move ahead:
      prev = curr;
      curr = next;
   }
   setrest(p, nullptr);
   p = prev;
   return p;
}
// Copy all the value of given node into new node:
Node *copy(Node *p)
{
   if (p == nullptr)
   {
      return nullptr;
   }
   return cons(first(p), copy(rest(p)));
}
//This fuction is used to add the given 
//element at the last end of linked list:
// A new node will be added at the last :
//This function works recursively:
Node *append(int x, Node *head)
{
   Node*p=head;
   if(rest(p)==nullptr)
   {
     //create a node:
     Node* newNode=new Node();
     setfirst(newNode,x);
     setrest(newNode,nullptr);
     //add this node on the last of linked list:
     setrest(p,newNode);
     return p;
   }
    append(x,rest(p));
    return head;
}
// if x is in list p:
// it will return true otherwise false:
bool searchInOrder(int x, Node *head)
{
    Node*p=head;
   //base case:
   if(p==nullptr || first(p)>x){
    return false;
   }
   else if(first(p)==x)
   {
    return true;
   }
   return searchInOrder( x, rest(p));
}
//This is a helper function that is used to for check duplicates:
bool checkDuplicates(int x, Node *head)
{
    Node *p = head;
    if (p == nullptr)
    {
        return false;
    }
    if (first(p) == x)
    {
        return true;
    }
    return checkDuplicates(x, rest(p));
}
// This function is used to check the duplicates in a linked list:
// it will return true ,if there are duplicates otherwise
// it will return false
bool hasDuplicates(Node *head)
{
    Node *p = head;
    if (p == nullptr)
    {
        return false;
    }

    int x = first(p);
    // base case:

    if (checkDuplicates(x, p))
    {
        return true;
    }
    return hasDuplicates(rest(p));
}
//This is a helper function that is used for isLonger function
//This function returns the size of given linked list
int sizeOfNode(int size, Node* head)
{
    Node *p=head;
    if(head==nullptr){
        return size;
    }
    size=size+1;
  return  sizeOfNode( size, rest(p));

}
// This will return true if ,p is longer than q:
bool isLonger(Node *p, Node *q)
{
   int sizeP = 0;
   int sizeQ = 0;
   //--if p has one or less elements :
   // p is longer:
   if (p != nullptr && q == nullptr)
   {
      return true;
   }
   // both are of same size:
   else if (p == nullptr && q == nullptr)
   {
      return false;
   }
   // if p is small er
   if (p == nullptr && q != nullptr)
   {
      return false;
   }
   
   sizeOfNode(sizeP,p);
  
   sizeOfNode(sizeQ,q);
   if (sizeP > sizeQ)
   {
      return true;
   }
   else
   {
      return false;
   }
}
