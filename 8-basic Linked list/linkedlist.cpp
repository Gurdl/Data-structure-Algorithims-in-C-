// Name:Gurdev singh
// Student number:100376466
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
using namespace std;
// returns the data field of the Node
//  if p is the nullptr, we cannot get its data ...exit abruptly
int first(Node *p)
{
   assert(p != nullptr);
   return (p->value);
}

// returns the link field of the Node
// if p is the nullptr, we cannot get its link.... exit abruptly
Node *rest(Node *p)
{
   assert(p != nullptr);
   return (p->link);
}

// change the value field (the first) of the Node pointed to by p
void setfirst(Node *p, int x)
{
   assert(p != nullptr);
   p->value = x;
}

// change the link field (the rest) of the Node pointed to by p
void setrest(Node *p, Node *q)
{
   assert(p != nullptr);
   p->link = q;
}
void setNull(Node *p)
{

   p->link = nullptr;
}
// create a new node with given value pointing to nothing:
Node *newNode(int x, Node *n)
{
   setfirst(n, x);
   setNull(n);
   return n;
}

// construct a new node (allocate dynamic memory that goes on the heap)
Node *cons(int x, Node *p)
{
   Node *q = new Node;
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
//    Node *p = head;
//    if (p == nullptr || rest(p) == nullptr)
//    {
//       return p;
//    }

//    Node *prev = p;
//    Node *curr = rest(p);
//    while (curr != nullptr)
//    {
//       Node *next = rest(curr);
//       setrest(curr, prev);
//       // Update the pointers to move ahead:
//       prev = curr;
//       curr = next;
//    }
//    setrest(p, nullptr);
//    p = prev;
//    return p;
// }
// // Copy all the value of given node into new node:
// Node *copy(Node *p)
// {
//    if (p == nullptr)
//    {
//       return nullptr;
//    }
//    return cons(first(p), copy(rest(p)));
    Node* temp=head;
        //If there is only one node or no node ,it is same as in
        //reverse linked list
        if(temp==nullptr || temp->link==nullptr){
            return temp;
        }
        //otheerwise:
        Node* prev=nullptr;
        Node* curr=temp;
        Node* nextNode=curr->link;
        while(curr!=nullptr)
        {
            curr->link=prev;
            prev=curr;
            curr=nextNode;
            if(nextNode!=nullptr)
            {
                nextNode=nextNode->link;
            }
        }
        head=prev;
        return head;
}
//This fuction is used to add the given 
//element at the last end of linked list:
// A new node will be added at the last :
Node *append(int x, Node *head)
{
   Node *p = head;
   Node *newNode = new Node();

   // if p is the null ptr:
   if (p == nullptr)
   {
      setfirst(newNode, x);
      setrest(newNode, nullptr);
      return newNode;
   }
   setfirst(newNode, x);
   setrest(newNode, nullptr);
   // now add this new node at the last of given linked list(p):
   while (rest(p) != nullptr)
   {
      p = rest(p);
   }
   setrest(p, newNode);
   return head;
}
// if x is in list p:
// it will return true otherwise false:
bool searchInOrder(int x, Node *head)
{
   Node *p = head;
   while (p != nullptr && first(p) <= x)
   {
      if (first(p) == x)
      {
         return true;
      }
      p = rest(p);
   }
   return false;
}
// This function is used to check the duplicates in a linked list:
//it will return true ,if there are duplicates otherwise
//it will return false
bool hasDuplicates(Node *p)
{
   while (p != nullptr && rest(p) != nullptr)
   {
      int x = first(p);
      bool ans = checkDulpicates(x, rest(p));
      if (ans)
      {
         return true;
      }
      p = rest(p);
   }
   return false;
}
// This is helper function for the above function:
bool checkDulpicates(int x, Node *head)
{
   Node *p = head;
   while (p != nullptr)
   {
      if (first(p) == x)
      {
         return true;
      }
      p = rest(p);
   }
   return false;
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
   // if p has more than one elements:
   while (p != nullptr || q != nullptr)
   {
      if (p != nullptr)
      {
         sizeP++;
      }
      if (q != nullptr)
      {
         sizeQ++;
      }
      if (p != nullptr)
      {
         p = rest(p);
      }
      if (q != nullptr)
      {
         q = rest(q);
      }
   }
   if (sizeP > sizeQ)
   {
      return true;
   }
   else
   {
      return false;
   }
}
// checks if the two passed liked list are equal by size and by value:
bool equal(Node *p, Node *q)
{
   int sizeP = 0;
   int sizeQ = 0;
   //--if p has one or less elements :
   // p is longer:
   if (p != nullptr && q == nullptr)
   {
      return false;
   }
   // both are of same size:
   else if (p == nullptr && q == nullptr)
   {
      return true;
   }
   // if p is small er
   if (p == nullptr && q != nullptr)
   {
      return false;
   }
   while (p != nullptr || q != nullptr)
   {
      // if values are not same:
      if (p != nullptr && q != nullptr)
      {
         if (first(p) != first(q))
         {
            return false;
         }
      }

      if (p != nullptr)
      {
         sizeP++;
      }
      if (q != nullptr)
      {
         sizeQ++;
      }
      if (p != nullptr)
      {
         p = rest(p);
      }
      if (q != nullptr)
      {
         q = rest(q);
      }
   }
   if (sizeP == sizeQ)
   {
      return true;
   }
   else
   {
      return false;
   }
}
// This function is used to make duplicate value of given linked list:
Node *makeDuplicates(Node *head)
{
   if (head == nullptr)
   {
      return nullptr;
   }
   // make a copy of given linked list:
   Node *newList = copy(head);
   Node *headNew = newList;
   Node *thirdNode;
   while (newList != nullptr && rest(newList) != nullptr)
   {
      thirdNode = rest(newList);
      Node *newNode = new Node();
      int x = first(newList);
      setfirst(newNode, x);
      setrest(newList, newNode);
      // update:
      setrest(newNode, thirdNode);
      newList = thirdNode;
   }
   int lastValue = first(newList);
   Node *last = new Node();
   setfirst(last, lastValue); // last node:
   setrest(last, nullptr);
   setrest(newList, last);
   return headNew;
}
// This function is used to delete the linked list
//  and it return nullptr:
Node *deleteList(Node *head)
{
   // if head is already nullptr:
   if (head == nullptr)
   {
      return nullptr;
   }
   Node *curr = head;
   Node *next = rest(curr);
   while (curr != nullptr)
   {
      next = rest(curr);
      setrest(curr, nullptr);
      delete curr;
      curr = next;
   }
   return curr;
}
// This function is used to copy all the elements of Array A into linked list:
Node *array2List(int A[], int n)
{
   if (n == 0)
   {
      return nullptr;
   }
   // create a linked list:
   Node *list;
   for (int i = 0; i < n; i++)
   {
      int x = A[i];
      list = append(x, list);
   }
   return list;
}
// This meregd list is sorted and will contain both values of p and q:
Node *mergeTwoOrderedLists(Node *p, Node *q)
{
   // create two pinters foe given p and q:
   Node *pHead = p;
   Node *qHead = q;
   // create a merge list:
   // Node *mergedList;
   // // untill both p and q are same
   // while (pHead != nullptr && qHead != nullptr)
   // {
   //    int pValue = first(pHead);
   //    int qValue = first(qHead);
   //    int smallest;
   //    if (pValue < qValue)
   //    {
   //       smallest = pValue;
   //       // now update:
   //       pHead = rest(pHead);
   //    }
   //    else
   //    {
   //       smallest = qValue;
   //       // now update q:
   //       qHead = rest(qHead);
   //    }
   //    mergedList = append(smallest, mergedList);
   // }
   // // if p still have elemenst:
   // while (pHead != nullptr)
   // {
   //    int pValue = first(pHead);
   //    mergedList = append(pValue, mergedList);
   //    pHead = rest(pHead);
   //    //mergedList->link=pHead;
   // }
   // while (qHead != nullptr)
   // {
   //    int qValue = first(qHead);
   //    mergedList = append(qValue, mergedList);
   //    qHead = rest(qHead);
   // }
   // return mergedList;
   // ListNode* pHead=list1;
   //      ListNode* qHead=list2;
        //pointers for final:
        Node* finalHead=nullptr;
        Node* curr=nullptr;
        //if one of each is nullptr
        if(pHead==nullptr){
            return qHead;
        }
        if(qHead==nullptr){
            return pHead;
        }
        //Need the head for final
        if(pHead && qHead )
        {
            int val1=pHead->val;
            int val2=qHead->val;
            if(val1<val2)
            {
                finalHead=pHead;
                curr=pHead;
                pHead=pHead->link;

            }
            else{
                finalHead=qHead;
                curr=qHead;
                qHead=qHead->link; 
            }

        }
        while(pHead && qHead)
        {
            int val1=pHead->val;
            int val2=qHead->val;
            if(val1<val2)
            {
                //curr=curr->link;
                curr->link=pHead;
                curr=curr->link;
                pHead=pHead->link;

            }
            else{
               curr->link=qHead;
                curr=curr->link;
                qHead=qHead->link; 
            }
        }
        if(pHead)
        {
            curr->link=pHead;
                curr=curr->link;
            pHead=pHead->link;
        }
        if(qHead)
        {
           curr->link=qHead;
                curr=curr->link;
            qHead=qHead->link;
        }
        //return finalHead;
    
}
// remove all occurenec of x in given linked list:
Node *removeAll(int x, Node *head)
{

   if (head == nullptr)
   {
      return nullptr;
   }

   int value = first(head);
   Node *next = rest(head);
   // if head contains the x move the head:
   while (value == x)
   {
      if (head == nullptr)
      {
         return head;
      }
      next = rest(head);
      if (next != nullptr)
      {
         value = first(next);
      }
      else
      {
         value = x - x;
      }
      setrest(head, nullptr);
      head = next;
   }
   Node *prev = head;
   Node *curr = rest(prev);
   while (curr != nullptr)
   {

      if (first(curr) == x)
      {
         prev = del(prev);
      }
      else
      {
         prev = rest(prev);
      }
      if(prev!=nullptr)
      {
        curr = rest(prev);
      }
      else{
         curr=nullptr;
      }
      
   }

   return head;
}
// This method will delete the node next to the previous and will connect prev
// to the the next of deleted node:
Node *del(Node *prev)
{
   Node *deleteIt = rest(prev); // This need to delete:
   Node *next = rest(deleteIt);
   setrest(deleteIt, nullptr);
   delete deleteIt;
   setrest(prev, next);

   return next;
}
