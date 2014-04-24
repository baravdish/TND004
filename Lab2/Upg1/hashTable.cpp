#include "hashTable.h"
#include <iomanip>

#ifndef DOXYGEN_SHOULD_SKIP_THIS


/** \brief Test whether a number is a prime.
*
* \param n an integer.
* \pre true, if n is prime. Otherwise, return false.
*
*/
//function to test if a number is prime
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}


/** \brief Calculate the the next prime k such that k >= n .
*
* \param n an integer.
* \pre n is larger than zero.
* \pre a prime number larger or equal to n.
*/
//function to find a prime number at least as large as n
int nextPrime( int n )
{
    if( n % 2 == 0 )
        n++;

    for(; !isPrime( n ); n += 2 );

    return n;
}


//constructor
//TO IMPLEMENT
HashTable::HashTable(int tableSize, HASH f, int ml)
 : h(f), MAX_LOAD(ml)
{
  // h är pekare till hash-funktionen som tar in en string och en int, precis som typedef void (*fun_ptr)(int) och fun_ptr funny_array[10] = {10}
  primeTableSize = nextPrime(tableSize);



  theLists.resize(primeTableSize);
  nItems = 0;

  // KANSKE KÖTTA IN HELA DIC:EN I HASHTABELLEN?
}


//Empty the table
//The Items stored in the collison lists are deleted and the lists are emptied
//TO IMPLEMENT
void HashTable::makeEmpty()
{
    for(unsigned int i = 0; i < primeTableSize; i++)
    {
        if(!theLists.at(i).empty())
        {
            theLists.at(i).clear();
        }
    }
}


//destructor
HashTable::~HashTable()
{
    makeEmpty();

    nItems = 0;

    cout << "** Hash Table Destructor" << endl;
}


//Return the load factor of the table
//TO IMPLEMENT
double HashTable::loadFactor() const
{
    return (double)(nItems/(double)primeTableSize);
}


//Rehashing function
//TO IMPLEMENT
void HashTable::reHash()
{
    cout << "** Re-hashing ..." << endl;
    cout << "Hash table load factor = "
        << fixed << setprecision(2)
        << loadFactor() << endl;

    //ADD CODE
/*   int newTablesize = nextPrime(2*tableSize);
   for(0 till tableSize)
   {
      index = hashfunktion(theLists(i), newTableSize)
   }
*/


     cout << "** Re-hashing completed ..." << endl;
     cout << "Hash table load factor = "
          << fixed << setprecision(2)
          << loadFactor() << endl;
 }

//Return a pointer to the item that matches word w
//If w does not belong to the table then return nullptr
//TO IMPLEMENT
Item* HashTable::find(string w) const
{
   int i = h(w, primeTableSize);
   list<Item*>::const_iterator it = theLists[i].begin();

   if(!theLists[i].empty())
   {
      //itemPtr = &(*it);

      for(; it != theLists[i].end(); ++it)
      {
		 if((*it)->word == w )
         {
			 return *it;
         }
      }
   }


   //for_each(theLists[i].begin(), theLists[i].end(), compare(theLists[i]));


   /*
   Item *itemPtr;
   int i = h(w, primeTableSize);
   list<Item*> test;
   test = theLists[i];
   list<Item*>::iterator it = test.begin();
   itemPtr = *it;

   if(itemPtr->word == w)
   {
      return itemPtr;
   }
   return nullptr;*/
   return nullptr;
}


//Insert item w with counter i into the hash table
//Return a pointer to the inserted item
//Assumes w is not in the table
//TO IMPLEMENT
Item* HashTable::insert(string w, short i)
{
   // ASSUME W IS NOT IN THA TABBLE!!!
   // behöver ej hantera kollision då!

   int index = h(w, primeTableSize);

   nItems++;
   Item *itemPtr = new Item(w,i);
   theLists[index].push_back(itemPtr);
   return itemPtr;
   //theLists[index].push_back(itemPtr);

}


//Remove item w from the hash table
//If w belongs to the table then return true,
//otherwise, return false
//TO IMPLEMENT
bool HashTable::remove(string w)
{
   // OM ORDET HITTAS, DÅ SKA nItems--, ANNARS INTE
   nItems--;
   return false;
}


//Overloaded operator<<: outputs all items to stream os
//TO IMPLEMENT
ostream& operator <<(ostream& os, const HashTable& T)
{
   //ADD CODE
    return os;
}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */

