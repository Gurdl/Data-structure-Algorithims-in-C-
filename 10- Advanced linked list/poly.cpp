// Name:Gurdev singh
// Student Number: 100376466

// CPSC 1160, Assignment #10
// initial code written by Gladys and Michael Monagan, CPSC 1160

#include "poly.h"
#include <iostream>
using namespace std;

// changes this->variable to w
void Sparse::setPrintVariable(char w)
{
   this->variable = w;
}

// returns the variable used in outputting the polynomial
char Sparse::getPrintVariable() const
{
   return this->variable;
}

// the zero polynomial i.e. the constant zero
Sparse::Sparse() : variable(DEFAULT_VARIABLE)
{
   Sparse::variable = 'x';
   Sparse::poly = nullptr;
}

// creates the term  c*x^d and sets the polynomial to this term
// O(1)
Sparse::Sparse(int c, int d) : variable(DEFAULT_VARIABLE)
{
   Sparse::Node *p = new Node;
   // create term:
   Sparse::Term *t = new Term;
   t->coeff = c;
   t->degree = d;
   // create a linked list with required values:
   p->term = t;
   p->link = nullptr;
   Sparse::poly = p;
}

// basically, checks the representation of the zero polynomial
// O(1)
bool Sparse::isZeroSparse() const
{
   if (Sparse::poly == nullptr)
   {
      return true;
   }
   return false;
}

int Sparse::degree() const
{
   // if poly is zero poly:
   if (Sparse::poly == nullptr)
   {
      return -1;
   }
   // else:
   Sparse::Node *p = Sparse::poly; // iterator on poly
   while (p->link = nullptr)       // reach at last elem:
   {
      p = p->link;
   }
   int degre = p->term->degree;
   return degre;
}

// returns the coefficient of the term which has degree d
int Sparse::coefficient(int d) const
{
   if (Sparse::poly == nullptr)
   {
      return 0;
   }
   Sparse::Node *p = Sparse::poly;
   while (p != nullptr)
   {
      if (p->term->degree == d)
      {
         return p->term->coeff;
      }
      p = p->link;
   }
   return 0;
}

// outputs the polynomial term by term
// it uses the linked list poly and the instance variable this->variable
// do not output  "+ -" when outputting negative coefficients
// outputing is O(n) where n is the number of terms of the polynomial f
std::ostream &operator<<(std::ostream &out, const Sparse &f)
{
   // make a special case for the poly that has no terms i.e. the zero polynomial
   // CPSC 1160 fill in the code below
   if (f.poly == nullptr)
   {
      out << '0';
      return out;
   }
   // get the private list poly from f
   Sparse::Node *p = f.poly;
   // variable is a private member of f
   char x = f.variable;
   bool first_term = true;
   while (p != nullptr)
   {
      int c = p->term->coeff;
      int d = p->term->degree;
      if (d == 0)
      { // do not output "x^0"
         out << c;
      }
      else
      {
         // the degree d  > 0
         if (c > 0)
         {
            if (!first_term)
               out << " + ";
            if (c != 1)
            {
               out << c << "*";
            }
         }
         else
         {
            // c < 0, could not be c == 0
            out << " - ";
            if (c != -1)
            {
               out << -c << "*";
            }
         }
         out << x << "^" << d;
      }
      // get the next Node
      p = p->link;
      first_term = false;
   } // while
   return out;
}
// add x
Sparse::Node *Sparse::cons(Term *x, Node *p)
{
   Node *q = new Node;
   q->term = x;
   q->link = p;
   return q;
}

// copy
Sparse ::Node *Sparse::copyList(Sparse::Node *p)
{
   if (p == nullptr)
   {
      Sparse::Node *newNode = nullptr;
      return newNode;
   }
   return cons(p->term, copyList(p->link));
}
// return a new sparse polynomial
Sparse Sparse::operator*(int c) const
{
   // created a object:
   Sparse mult;
   if (c == 0)
   {
      return mult;
   }
   // created a new poly:
   Sparse::Node *head = Sparse::copyList(poly);
   Sparse::Node *p = head; // to iterate on new linked list:
   if (head == nullptr)
   {
      return mult;
   }
   while (p != nullptr)
   {
      p->term->coeff = c * p->term->coeff;
      p = p->link;
   }
   mult.poly = head;
   return mult;
}

// insert t in order into poly (based on degree using linear search)
// do not make a new copy of t
// O(n) for n terms which is the length of the linked list poly
void Sparse::insert(Sparse::Term *t)
{
   this->poly = insert(t, this->poly);
}

// insert t based on degree into p and return the list with t in it
// do not make a new copy of t
// delete t if t cannot be inserted
// return a linked list which is p modified
// O(n) where n is the length of the linked list p
Sparse::Node *Sparse::insert(Term *t, Node *p)
{
   int c = t->coeff;
   int d = t->degree;
   if (d == 0)
   {
      delete t;
      return p;
   }
   if (p == nullptr)
   {
      // cout<<"When p is nullptr"<<p->term->degree<<endl;
      Node *q = new Node;
      q->term = t;
      q->link = nullptr;
      return q;
   }
   Node *head = p;
   Node *prev = p;

   while (p->link != nullptr && p->term->degree <= d)
   {
      prev = p;
      p = p->link;
   }
   // add at last:
   if (p->link == nullptr && p->term->degree <= d)
   {
      Node *q = new Node;
      q->term = t;
      q->link = nullptr;
      p->link = q;
      return head;
   }
   // add in middle:
   Node *q = new Node;
   q->term = t;
   q->link = p;
   prev->link = q;
   return head;
}

// CPSC 1160: code has been started but is NOT complete
std::istream &operator>>(std::istream &in, Sparse &p)
{
   int numTerms;
   in >> numTerms;
   if (in && numTerms >= 0)
   {
      int c; // a coefficient
      int d; // a degree
      for (int i = 0; i < numTerms; i++)
      {
         // Sparse::Term *t;
         //  t->coeff=c;
         //  t->degree=d;
          in >> c >> d;
         Sparse l(c, d);
         p.insert(l.poly->term);
        
      }
   }
   return in;
}

// use a merge type of algorithm to add the two polynomials f and g
// (which have sorted lists)
// in the worst case, the addition is the sum of the length of "f"
// plus the length of "g"
// so if f has n terms and g has m terms, it is O(n+m)
Sparse operator+(const Sparse &f, const Sparse &g)
{
   Sparse final;
   // This all will merge the two lists:
   Sparse::Node *p = Sparse::copyList(f.poly);
   Sparse::Node *q = Sparse::copyList(g.poly);
   Sparse::Node *mergedList = nullptr;
   Sparse::Node *head = nullptr;
   if (p == nullptr)
   {
      return g;
   }
   if (q == nullptr)
   {

      return f;
   }
   // add the head on merged:
   if (p && q)
   {
      if (p->term->degree <= q->term->degree)
      {
         mergedList = p;
         p = mergedList->link;
      }
      else
      {
         mergedList = q;
         q = mergedList->link;
      }
   }
   head = mergedList;
   // Now keep adding the rest as on tail (mergedList)
   while (p && q)
   {
      if (p->term->degree <= q->term->degree)
      {
         mergedList->link = p;
         mergedList = p;
         p = mergedList->link;
      }
      else
      {
         mergedList->link = q;
         mergedList = q;
         q = mergedList->link;
      }
   }
   if (p == nullptr)
   {
      mergedList->link = q;
   }
   if (q == nullptr)
   {
      mergedList->link = p;
   }

   final.poly = final.sum(head);

   return final;
}
Sparse::Node *Sparse::sum(Node *head)
{
   // Now add acordingly:
   Sparse::Node *curr = head;
   Sparse::Node *prev = nullptr;
   Sparse::Node *next = curr->link;
   // add right head:
   while (next != nullptr)
   {
      next = curr->link;
      if (curr->term->degree == next->term->degree)
      {
         Sparse::Node *newNode = next;
         int c = curr->term->coeff + next->term->coeff;
         int d = curr->term->degree;
         newNode->term->coeff = c;
         newNode->term->degree = d;
         if (prev != nullptr)
         {
            prev->link = newNode;
            curr = newNode;
         }

         if (prev == nullptr)
         {
            head = newNode;
         }
      }
      prev = curr;
      curr = next;
      next = next->link;
   }
   return head;
}

Sparse operator-(const Sparse &f, const Sparse &g)
{
   Sparse final;
   // This all will merge the two lists:
   Sparse::Node *p = Sparse::copyList(f.poly);
   Sparse::Node *q = Sparse::copyList(g.poly);
   Sparse::Node *mergedList = nullptr;
   Sparse::Node *head = nullptr;
   if (p == nullptr)
   {
      return g;
   }
   if (q == nullptr)
   {

      return f;
   }
   // add the head on merged:
   if (p && q)
   {
      if (p->term->degree <= q->term->degree)
      {
         mergedList = p;
         p = mergedList->link;
      }
      else
      {
         mergedList = q;
         q = mergedList->link;
      }

   }
   head = mergedList;
   // Now keep adding the rest as on tail (mergedList)
   while (p && q)
   {
      if (p->term->degree <= q->term->degree)
      {
         mergedList->link = p;
         mergedList = p;
         p = mergedList->link;
      }
      else
      {
         mergedList->link = q;
         mergedList = q;
         q = mergedList->link;
      }
   }
   if (p == nullptr)
   {
      mergedList->link = q;
   }
   if (q == nullptr)
   {
      mergedList->link = p;
   }
   final.poly = final.sub(head);

   return final;

}
Sparse::Node *Sparse::sub(Node *head)
{
   // Now add acordingly:
   Sparse::Node *curr = head;
   Sparse::Node *prev = nullptr;
   Sparse::Node *next = curr->link;
   // add right head:
   while (next != nullptr)
   {
      next = curr->link;
      if (curr->term->degree == next->term->degree)
      {
         Sparse::Node *newNode = next;
         int c = curr->term->coeff - next->term->coeff;
         int d = curr->term->degree;
         newNode->term->coeff = c;
         newNode->term->degree = d;
         if (prev != nullptr)
         {
            prev->link = newNode;
            curr = newNode;
         }

         if (prev == nullptr)
         {
            head = newNode;
         }
      }
      prev = curr;
      curr = next;
      next = next->link;
   }
   return head;
}

Sparse::Sparse(const Sparse &other) : variable(other.variable)
{
   if (other.poly == nullptr)
   {
      this->poly = nullptr;
   }
   Sparse::Node *copy = Sparse::copyList(other.poly);
   this->variable = other.variable;
   this->poly = copy;
}

Sparse &Sparse::operator=(const Sparse &rhs)
{
   if (this != &rhs)
   {
      this->poly = Sparse::deleteList(this->poly); // delete what we have to avoid memory leaks
      if (rhs.poly == nullptr)
      {
         this->poly = nullptr;
         return *this;
      }
      Sparse::Node *copy = Sparse::copyList(rhs.poly);
      this->poly = copy;
      this->variable=rhs.variable;
   }
   return *this;
}

Sparse::~Sparse()
{
    
   this->poly = deleteList(this->poly);
}
// This will delete the list
Sparse::Node *Sparse::deleteList(Node *p)
{
   if (p == nullptr)
   {
      return nullptr;
   }
   while (p != nullptr)
   {
      Sparse::Node *discard = p->link;
      delete p;
      p = discard;
   }
   p = nullptr;
   return p;
}

// BONUS
// This function will do the 
//dervative and returned the required value
Sparse Sparse::derivative() const
{
   Sparse der;
   der.poly = Sparse::copyList(this->poly);

   Sparse::Node *p = der.poly;
   Sparse::Node *head = p;
   while (p != nullptr)
   {
      int d = p->term->degree;
      int c = p->term->coeff;
      Sparse::Node *newNode = p;
      newNode->term->coeff = d * c;
      newNode->term->degree = d - 1;

      newNode->link = p->link;
      p = p->link;
   }
   der.poly = head;
   return der;
}
