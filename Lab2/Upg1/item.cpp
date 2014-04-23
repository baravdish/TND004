#include <iomanip>

#include "item.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

//Constructor
Item::Item (string w, short c)
  : word (w), counter (c)
{
//   std::cout << "Constructor Item" << std::endl;
}


//Overloaded operator<<
ostream& operator << (ostream& os, const Item& i)
{
    os << setw(25) << i.word
       << "   Counter: " << i.counter << endl;

    return os;
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
