#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "item.h"

#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;


/** \brief Class to represent an hash table
 *
 * The elements stored in the table are pointers to Items (Item*)
 * \note Collision resolution strategy: separate chaining.
 * \note TND004, Lab 2 -- class not implemented.
 */
//Class to represent an hash table storing pointers to Items (Item*)
class HashTable
{
    public:

    /** \brief Type HASH is a pointer to an hash function for strings.
    *
    */
    typedef unsigned (*HASH)(string, int); //new type HASH: pointer to an hash function


   /** \brief Constructor.
    *
    * \param TableSize number of slots in the table.
    * \param f a (pointer to an) hash function.
    * \param ml maximum number of Items allowed on average in the collision lists.
    *
    */
   // Constructor
   //TO IMPLEMENT
   HashTable(int TableSize, HASH f, int ml);


   /** \brief Destructor.
    *
    * Remove all Items stored in the table.
    *
    */
   //destructor
   ~HashTable();


    /** \brief Get the load factor of the table.
    *
    * \return Load factor of the table (double).
    *
    */
   //Return the load factor of the table
   //TO IMPLEMENT
   double loadFactor() const;


    /** \brief Find the Item storing a word w.
    *
    * \param w a string representing a word.
    * \pre w should be in lower-case letters and without punctuaction signs.
    * \return A pointer to the item that matches word w, if w is in the table. Otherwise, nullptr is returned.
    *
    */
    //Return a pointer to the item that matches word w
	//If w does not belong to the table then return nullptr
	//TO IMPLEMENT
	Item* find(string w) const;


    /** \brief Insert a new Item in the table.
    *
    * \param w a string representing a word.
    * \param i misspelings counter (can be zero).
    * \pre w should be in lower-case letters and without punctuaction signs.
    * \note It is assumed that w is not in the table.
    * \return a pointer to the newly inserted Item.
    *
    */
    //Insert item w with counter i into the hash table
    //Return a pointer to the inserted item
    //Assumes w is not in the table
	//TO IMPLEMENT
	Item* insert(string w, short i = 0);


	/** \brief Remove Item storing a word from the hash table.
    *
    * \param w a string representing a word.
    * \pre w should be in lower-case letters and without punctuaction signs.
    * \return true, if w is in the table. Otherwise, return false.
    *
    */
	//Remove item w from the hash table
	//If w belongs to the table then return true,
	//otherwise, return false
	//TO IMPLEMENT
	bool remove(string w);


	/** \brief Overloaded operator<<
    *
    * Outputs all items in the table to stream os.
    * \param os ostream object where characteres are inserted.
    * \param T hash table to be displayed.
    * \return The same as parameter os.
    *
    */
	//Outputs all items in the table to stream os
	//TO IMPLEMENT
   friend ostream& operator<<(ostream& os, const HashTable& T);

	private:
	//data members

       //number of itms stored in the table
       int nItems;  /**< Number of items stored in the table */
       
       //hash function
       const HASH h; /**< Hash function */

       //Max allowed load factor for the hash table
       //When the max load factor is exceeded rehashing should occur
       const double MAX_LOAD; /**< Max allowed load factor for the hash table, i.e. max number of nodes in the collision lists on average.*/

       //table of collision lists
       //each collision list is an std::list container
       //each node stores a pointer to an Item
       vector<list<Item*>> theLists; /**< A table of collision lists: each node stores a pointer to an Item */


   /** \brief Rehashing function.
    *
    * \return None
    *
    */
   //Rehashing function
   //TO IMPLEMENT
   void reHash();


   /** \brief Empty the table
    *
    * The Items stored in the collison lists are deleted and the lists are emptied
    * \return None
    *
    */
   //Empty the table
   //The Items stored in the collison lists are deleted and the lists are emptied
   //TO IMPLEMENT
   void makeEmpty();


   /** \brief Disabled copy constructor.
    *
    */
   //disable copy constructor
   HashTable(const HashTable &);


    /** \brief Disabled assignment operator.
    *
    */
   //disable assignment operator
   const HashTable & operator=(const HashTable &);

};

#endif
