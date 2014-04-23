/*
  Name: item.h
  Author:
  Course: TND004, Lab 2
  Description: class Item
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;


/** \brief Class to represent an item stored in an hash table.
 *
 * Every item consists of a word+counter
 * \author Aida Nordman
 * \date March, 2014
 * \note TND004, Lab 2 -- class Item is fully implemented
 */
//Class to represent an item stored in an hash table
//Every item consists of a word+counter
class Item
{
    /** \brief Constructor
    *
    * \param w a string representing a word in lower-case letters without punctuation signs.
    * \param c a short int representing a counter of the number of times w occurs as a missplelling.
    *
    */
    // Constructor
    Item (string w = "", short c = 0);

    //data members
    string word;     /**< a word */
    short counter;    /**< if counter > 0 then w is a misspelled word with counter occurrences. If counter == 0 then w is not a misspelling*/
    //if counter > 0, counter is the number of times the misspelling occurs
    //if counter == 0, it is a correct word

    /** \brief Overloaded operator<<
    *
    * \param os ostream object where characteres are inserted
    * \param i Item to be displayed
    * \return The same as parameter os
    *
    */
    friend ostream& operator <<(ostream& os, const Item& i);

    friend class HashTable;
    friend class SpellChecker;
};

#endif
