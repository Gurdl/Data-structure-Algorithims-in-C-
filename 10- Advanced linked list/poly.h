// Name:Gurdev singh
// Student Number:100376466
// Code Design by Gladys and Michael Monagan
// Do not post anywhere

#ifndef SPARSE_H
#define SPARSE_H

#include <iostream>

class Sparse {
   public :
      // creates the zero polynomial
      // the default character getPrintVariable() is 'x'
      Sparse(); 

      // creates a sparse polynomial with one term   c*x^n
      Sparse(int c, int n); 

      // returns true if this polynomial is the zero polynomial (the constant 0), 
      // false otherwise
      bool isZeroSparse() const;

      // returns the degree of this sparse polynomial
      // as a special case, it returns -1 for the zero polynomial
      int degree() const; 

      // returns the coefficient of the term (in the polynomial) of degree n 
      // if there is no term with degree n, returns 0
      int coefficient(int n) const; 

      // reads the sparse polynomial using the open input stream 
      // enter first an integer for the number of terms 
      // enter then pairs of integers for each term corresponding to the
      // the coefficient and the degree of the term
      // 
      // the zero polynomial can be entered as the coefficient 0 
      // followed by any degree
      // 
      // Note that internally there are no nodes with a zero coefficient so the
      // zero polynomial is a special case
      // 
      // Hint: if the coefficient of the term is 0, do not insert it into 
      // the sparse polynomial
      friend std::istream& operator >> (std::istream&, Sparse&);
   
      // prints the sparse polynomial with the variable (set with setPrintVariable)
      friend std::ostream& operator << (std::ostream&, const Sparse&);

      // multiply the sparse polynomial by the (scalar) constant c
      // c could be negative
      // returns a new sparse polynomial 
      // multiplying by c = 0 returns the zero polynomial
      Sparse operator *(int c) const;

      // add the sparse polynomials f and g
      // return the sum f + g as a new polynomial
      friend Sparse operator + (const Sparse& f, const Sparse& g);

      // subtract the sparse polynomial g from the sparse polynomial f
      // return the difference f - g as a new polynomial
      // CPSC 1160 hint: implement using the operator * and the operator +
      friend Sparse operator - (const Sparse& f, const Sparse& g);

      // changes the character used to output the sparse polynomial
      // Examples outputs x^2 if variable is 'x' and y^2 is variable is 'y'
      void setPrintVariable(char variable);

      // return the variable used in outputting the sparse polynomial
      char getPrintVariable() const;

      Sparse(const Sparse&); 

      Sparse& operator = (const Sparse&);

      ~Sparse();

      // CPSC 1160 BONUS
      // compute the derivative of the sparse polynomial
      // return the differentiated polynomial as a new sparse polynomial
      Sparse derivative() const;

   private:
      struct Term {
         int coeff;
         int degree;
      };

      // the sparse polynomial is represented using a linked list
      // each node in the linked list corresponds to a term
      struct Node {
         Term* term;  // CPSC 1160 use a pointer as defined here
         Node* link;
      };
         
      // The linked list poly is sorted in ascending order on the degree 
      // of each term so that polynomial addition and subtraction 
      // can be done in linear time using merging. 
      // Do not store a term with a zero coefficient (with the exception of
      // the zero polynomial which you need NOT represent with a struct Term )
      Node * poly;

      static const char DEFAULT_VARIABLE = 'x';
      
      // when outputting the polynomial, 
      // use the variable as the output character
      char variable;
      
      // creates a sparse polynomial with the p passed
      // a private constructor useful when we have the list already built
      // does not make a copy of p
      // Sparse(Node *p);

      // insert the (already allocated) term t into this->poly
      void insert(Term *t); 
      static Node* insert(Term* t,Node* p);
      
      // insert the (already allocated) term t into the linked list p
      // no copy of t is made
      // The insert operation needs to insert the term in order (based
      // on the term's degree). If a term in the linked list poly has
      // the same degree as the term to be inserted, only the terms'
      // coefficients are added (and there is also the situation where
      // the term in the linked list might to be deleted due to cancellation,
      // including possibly t as well).
      // So poly is always sorted and never has duplicate terms nor do 
      // two terms in the linked list have the same degree.
      // deletes all the nodes and all the terms of the linked list p 
      // returns the nullptr
      static Node* deleteList(Node *p);
      static Node* sum(Node *p);
       static Node* sub(Node *p);

      
      // returns a deep copy of the linked list p
      // p is not changed in copyList
      static Node *cons(Term*x , Node *p);
      static Node* copyList(Node *p);




};

#endif

// copyright 2022 Gladys Monagan
