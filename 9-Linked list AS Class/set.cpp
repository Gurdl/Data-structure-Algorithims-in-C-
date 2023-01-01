// Name:Gurdev singh
// Student Number: 100376466
#include <cassert>
#include <sstream> // std::stringstream
#include <iostream>
#include <string>
#include "set.h"
#include "set_utils.h"
using namespace std;
// using monagan::operator >>;
using std::stringstream, std::string;
// if you do want debugging statements, comment out the next statement
#define NDEBUG
// constructor
Set::Set() : list(nullptr)
{
   // no body
}
// The time complexity is o(1)
bool Set::isEmpty() const
{
   return (list == nullptr);
}

// depends on the complexity of length in Node.cpp which is O(n)
// precondition:
//    list has been initialized to either a valid address or the nullptr
int Set::size() const
{
   Node *p = list;
   if (list == nullptr)
   {
      return 0;
   }
   int size = 0;
   while (p != nullptr)
   {
      size++;
      p = p->next;
   }
   return size;
}

// make a new node and put in the value field x and in the next field p
// precondition: none
// postcondition:
//   a pointer to the newly created Node is returned
// complexity: O(1)
Set::Node *Set::cons(int x, Node *p)
{
   Node *q;
   q = new Node;
   q->value = x;
   q->next = p;
   return q;
}

// do a destructive reverse of the list
// there are n elements in the list pointed to by p
// postcondition:
// returns a reversed list with all the nodes of p
//
// if there are n elements in the list,the complexity of reverse is O(n)
Set::Node *Set::reverse(Node *p)
{
   Node *curr, *after;
   // if p is empty or if there is only one node, return p
   if (p == nullptr || p->next == nullptr)
      return p;
   // after points to one ahead, curr has the current node,
   // p has the previous node so that after the reverse
   // we can have after, curr and then p
   curr = p->next;
   // the following node is going to become the last node in the list
   p->next = nullptr;
   while (curr != nullptr)
   {
      after = curr->next;
      curr->next = p;
      p = curr;
      curr = after;
   }
   return p;
}

// if there are n elements in the list,the complexity of memeber is O(n)
bool Set::member(int x) const
{
   Node *p = list;
   if (list == nullptr)
   {
      return false;
   }
   while (p != nullptr)
   {
      if (x == p->value)
      {
         return true;
      }
      p = p->next;
   }
   return false;
}
// Mostly it depend on the value of n but on an
// averge or worst case we can say O(n)
void Set::insert(int x)
{
   Node *head = list;
   if (list == nullptr)
   {
      list = cons(x, nullptr);
      return;
   }
   // if we need to add at first;
   if (x < list->value)
   {
      list = cons(x, list);
      return;
   }
   Node *prev = head;
   while (head != nullptr && x >= head->value)
   {
      // if x already exist,just exit
      if (head->value == x)
      {
         return;
      }
      prev = head;
      head = head->next;
   }

   Node *newNode = cons(x, nullptr);
   prev->next = newNode;
   newNode->next = head;
}
// It also depend on the value of x whether it is at the strating or at end
// On an average its is O(n)
void Set::remove(int x)
{
   Node *head = list;
   if (head == nullptr)
   {
      return;
   }

   Node *prevHead = list;
   // if head contains the x move the head:
   while (list && list->value == x)
   {
      prevHead = list;
      list = list->next;
   }
   Node *curr = list;
   Node *prev = nullptr;

   while (curr)
   {
      if (curr->value == x)
      {
         Node *prevHead2 = curr;
         prev->next = curr->next;
         prevHead2 = nullptr;
      }
      else
      {
         prev = curr;
      }
      curr = curr->next;
   }
}
// output onto out a list of the form { element0 element 1  ... elementn-1 }
// precondition:
//  Set s is a valid, well initialized Set
// complexity of printing the list is O(n) when there are n elements in the Set s
std::ostream &operator<<(std::ostream &out, const Set &s)
{
   out << "{ ";
   for (Set::Node *p = s.list; p != nullptr; p = p->next)
      out << p->value << " ";
   out << "}";
   return out;
}
// This function has complexity of O(n ) as it will copy all n elements;
Set ::Node *Set::copyList(Node *p)
{
   if (p == nullptr)
   {
      return nullptr;
   }
   return cons(p->value, copyList(p->next));
}
// static function:
// If m and n are the two sizs of linked list then
// Time complexity will be O(min(m,n))
Set::Node *Set::mergedList(Node *head1, Node *head2)
{
   Set::Node *p = Set::copyList(head1);
   Set::Node *q = Set::copyList(head2);
   Set::Node *mergedList = nullptr;
   Set::Node *head = nullptr;
   if (p == nullptr)
   {
      return q;
   }
   if (q == nullptr)
   {

      return p;
   }
   // add the head on merged:
   if (p && q)
   {
      if (p->value <= q->value)
      {
         mergedList = p;
         p = mergedList->next;
      }
      else
      {
         mergedList = q;
         q = mergedList->next;
      }
   }
   head = mergedList;
   // Now keep adding the rest as on tail (mergedList)
   while (p && q)
   {
      if (p->value <= q->value)
      {
         // do not add if value already exist
         if (mergedList->value == p->value)
         {
            p = p->next;
         }
         else
         {
            mergedList->next = p;
            mergedList = p;
            p = mergedList->next;
         }
      }
      else
      {
         if (mergedList->value == q->value)
         {
            q = q->next;
         }
         else
         {
            mergedList->next = q;
            mergedList = q;
            q = mergedList->next;
         }
      }
   }
   if (p == nullptr)
   {
      mergedList->next = q;
   }
   if (q == nullptr)
   {
      mergedList->next = p;
   }
   return head;
}
// If m and n are the two sizs of linked list then
// Time complexity will be O(max(m,n))
const Set operator+(const Set &a, const Set &b)
{
   Set copyA;
   copyA.list = Set::copyList(a.list);

   Set copyB;
   copyB.list = Set::copyList(b.list);

   Set merged;
   // Set head; // it will contains the head of merged list;

   Set::Node *headMerged = Set::mergedList(copyA.list, copyB.list);
   merged.list = headMerged;
   return merged;
}
// static function:
// This fuction will have complexity O(max(m,n))
const Set operator*(const Set &a, const Set &b)
{

   Set::Node *currA = a.list;
   Set::Node *currB = b.list;
   Set intersection;
   // create a pointer to transverse:
   Set::Node *head = nullptr;
   Set::Node *curr = nullptr;
   while (currA && currB)
   {
      if (currA->value == currB->value)
      {
         // add head
         if (head == nullptr)
         {
            // create a new Node:
            Set::Node *newNode = Set::cons(currA->value, nullptr);
            head = newNode;
            curr = newNode;
         }
         // add the second and further node:
         else
         {
            Set::Node *newNode = Set::cons(currA->value, nullptr);
            curr->next = newNode;
            curr = curr->next;
         }
         currA = currA->next;
         currB = currB->next;
      }
      // if there is no any data is same than increase the smaller one:
      else
      {
         if (currA->value < currB->value)
         {
            currA = currA->next;
         }
         else
         {
            currB = currB->next;
         }
      }
   }
   intersection.list = head;
   return intersection;
}
// test if a is a subset of b
// if n is the size of a then its O(n),it will check all values
// of a;
bool operator<(const Set &a, const Set &b)
{
   Set::Node *currA = a.list;
   Set::Node *currB = b.list;
   // empty set is the subset of everyone:
   if (currA == nullptr)
   {
      return true;
   }
   while (currA && currB)
   {
      // if both are same
      if (currA->value == currB->value)
      {
         currA = currA->next;
         currB = currB->next;
      }
      else
      {
         if (currB->value < currA->value)
         {
            currB = currB->next;
         }
         else if (currB->value > currA->value)
         {
            return false;
         }
      }
   }
   // if current A has some different elemnts than B ,its not a subset
   if (currB == nullptr && currA != nullptr)
   {
      return false;
   }
   return true;
}
// it will copy all elements of list so its O(n);
Set::Set(const Set &otherSet)
{
   if (otherSet.list == nullptr)
   {
      this->list = nullptr;
   }
   Set::Node *copy = Set::copyList(otherSet.list);
   this->list = copy;
}
// it will delete all elements of list so its O(n);
//  remove every node from p and return the memory to the heap
Set::Node *Set::deleteList(Node *p)
{
   if (p == nullptr)
   {
      return nullptr;
   }
   while (p != nullptr)
   {
      Set::Node *discard = p->next;
      delete p;
      p = discard;
   }
   p = nullptr;
   return p;
}
// destructor
// postcondition:
//    every Node in the list is deleted and the list is set to nullptr
// Complexity O(n)
Set::~Set()
{
   this->list = deleteList(this->list);
}

// overload the assignment operator
// It also copies all elements of set into another
// So its complexity is as O(n),if n are no.of elements
// in linked list
Set &Set::operator=(const Set &otherSet)
{
   if (this != &otherSet)
   {
      this->list = Set::deleteList(this->list); // delete what we have to avoid memory leaks
      if (otherSet.list == nullptr)
      {
         this->list = nullptr;
         return *this;
      }
      Set::Node *copy = Set::copyList(otherSet.list);
      this->list = copy;
   }
   return *this;
}
// Bonus:
// This function will check all elemnts of a and b
// So it is most likely that its coplexity is O(n)
bool operator==(const Set &a, const Set &b)
{
   // pointers to iterate:
   Set::Node *currA = a.list;
   int sizeA = 0;
   Set::Node *currB = b.list;
   int sizeB = 0;
   while (currA && currB)
   {
      if (currA->value != currB->value)
      {
         return false;
      }
      sizeA++;
      sizeB++;
      currA = currA->next;
      currB = currB->next;
   }
   if (currA == nullptr && currB != nullptr)
   {
      return false;
   }
   if (currB == nullptr && currA != nullptr)
   {
      return false;
   }
   return true;
}
// This function also depened on the size of a if n is the size of a :
// As we want to check all the elements of a exist in b or not
// Then complexity is   O(n)
bool operator%(const Set &a, const Set &b)
{
   Set::Node *currA = a.list;
   Set::Node *currB = b.list;
   int sizeA = 0;
   int sizeB = 0;
   // if both set are empty it is not a proper subset
   if (currA == nullptr && currB == nullptr)
   {
      return false;
   }
   if (currA == nullptr && currB != nullptr)
   {
      return true;
   }
   while (currA && currB)
   {
      // if both are same
      if (currA->value == currB->value)
      {
         currA = currA->next;
         currB = currB->next;
         sizeA++;
         sizeB++;
      }
      else
      {
         if (currB->value < currA->value)
         {
            currB = currB->next;
            sizeB++;
         }
         else if (currB->value > currA->value)
         {
            return false;
         }
      }
   }
   // if current A has some different elemnts than B ,its not a subset
   if (currB == nullptr && currA != nullptr)
   {
      return false;
   }
   while (currB != nullptr)
   {
      sizeB++;
      currB = currB->next;
   }
   if (sizeA == sizeB)
   {
      return false;
   }
   // Now b must have one extra element to make a as proper subset:
   return true;
}
// copyright 2022 Gladys Monagan
