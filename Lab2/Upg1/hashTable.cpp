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
  // alltså: h(string w, short i) är "h pekar på samma adress som en funktion som tar in en string och en int och returnar en int"
  if(!isPrime(tableSize))
  {
    theLists.resize(nextPrime(tableSize));
  }
  else
  {
    theLists.resize(tableSize);
  	//reHash();
  }

  nItems = 0;

}


//Empty the table
//The Items stored in the collison lists are deleted and the lists are emptied
//TO IMPLEMENT
void HashTable::makeEmpty()
{
    for(unsigned int i = 0; i < theLists.size(); i++)
    {
        if(!theLists[i].empty())
        {
			list<Item*>::const_iterator it = theLists[i].begin();
			list<Item*>::const_iterator itPrev = theLists[i].begin();

			while(it != theLists[i].end())
			{
				++it;
				delete *itPrev;
				itPrev = it;
			}
			theLists[i].clear();
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
    return (double)( (double)nItems / (double)theLists.size() );
}


//Rehashing function
//TO IMPLEMENT
void HashTable::reHash()
{
    cout << "** Re-hashing ..." << endl;
    cout << "Hash table load factor = "
        << fixed << setprecision(2)
        << loadFactor() << endl;

	int newPrimeSize = nextPrime(2*theLists.size());

	if(!theLists.empty())
	{
		vector<list<Item*>> temp = theLists;

		theLists.clear();
		theLists.resize(newPrimeSize);

		for(int i = 0; i < temp.size(); i++)
		{
			if(!temp[i].empty())
			{
				for(list<Item*>::const_iterator it = temp[i].begin(); it != temp[i].end(); ++it)
				{
					// KANSKE MEMORY LEAK!!!!!!!!!!!!!!
					int index = h((*it)->word, theLists.size());
					Item *itemPtr = new Item((*it)->word,0);
					theLists[index].push_front(itemPtr);
				}
			}
		}
	}
	else
	{
		theLists.resize(newPrimeSize);
	}
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
   int i = h(w, theLists.size());
   list<Item*>::const_iterator it = theLists[i].begin();

   if(!theLists[i].empty())
   {
      for(; it != theLists[i].end(); ++it)
      {
		 if((*it)->word == w )
         {
			 return *it;
         }
      }
   }
   return nullptr;
}


//Insert item w with counter i into the hash table
//Return a pointer to the inserted item
//Assumes w is not in the table
//TO IMPLEMENT
Item* HashTable::insert(string w, short i)
{
   int index = h(w, theLists.size());
   nItems++;

   Item *itemPtr = new Item(w,i);
   theLists[index].push_front(itemPtr);
   if(loadFactor() > MAX_LOAD)
   {
        reHash();
   }
   return itemPtr;
}


//Remove item w from the hash table
//If w belongs to the table then return true,
//otherwise, return false
//TO IMPLEMENT
bool HashTable::remove(string w)
{
   int index = h(w, theLists.size());

   Item *itemPtr = find(w);

   if(itemPtr == nullptr)
		return false;

   theLists[index].remove(itemPtr);
   delete itemPtr;
   nItems--;

   return true;
}

//Overloaded operator<<: outputs all items to stream os
//TO IMPLEMENT
ostream& operator <<(ostream& os, const HashTable& T)
{
	// antingen med iterator eller med int i för att loopa genom vektorn
	list<Item*>::const_iterator it;
	cout<<"Size = " <<T.theLists.size() << endl;
	cout<<"Number of items in the table = " <<T.nItems << endl;
	cout<<"Load factor = "<< T.loadFactor() << endl;
	for(int i = 0; i < T.theLists.size(); i++)
	{
		cout<<"** List["<<i<<"]"<<endl;
		if(!T.theLists[i].empty())
		{
			for(it = T.theLists[i].begin(); it != T.theLists[i].end(); ++it)
			{
				os<<**it; // för att
				//i item.cpp är det:  operator<<(ostream& os, const Item& i) och *it pekar mot en lista medan **it pekar mot en lista som i sin tur har en pekare som pekar mot ett item
			}
		}
	}
    return os;
}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */



























