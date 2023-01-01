// CPSC 1160 
// Author: Gladys Monagan
// Do not post anywhere.

#include <iostream>
#include "set.h"
#include "set_utils.h"

namespace monagan {
   const int MAX_BUFFER = 200;
   std::istream& operator >> (std::istream& in, Set& s) {
      int x;
      while (in >> x) s.insert(x);
      in.ignore(MAX_BUFFER, '\n');
      in.clear();
      return in;
   }
}

// copyright 2022 Gladys Monagan
