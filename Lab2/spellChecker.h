#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include "HashTable.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;


/** \brief Class to represent a spell checker (as discussed in lecture 3).
 *
 * \note TND004, Lab 2 -- class not implemented
 */
//Class to represent a spell checker (as discussed in lec 3)
class SpellChecker
{
    public:

    /** \brief Constructor
    *
    * \param fileName name (string) of a text file with the dictionary.
    * \param n number of words in the dictionary.
    * \pre words in the text file are in lower-case letters without punctuation signs.
    *
    */
    //Constructor
    //Text file fileName should contain a dictionary with n words
    //TO IMPLEMENT
    SpellChecker(string fileName = "engDict.txt", int n = 49200);


    /** \brief Destructor
    *
    * Delete the hash table and the misspellings list.
    *
    */
    //Destructor
    //TO IMPLEMENT
    ~SpellChecker();


    /** \brief Test whether word w is in the dictionary.
    *
    * \param w a string representing a word.
    * \return true, if w is in the dictionary, otherwise false.
    * \note The misspeling list might be updated.
    * \note w is a misspelling if it is not in the dictionary.
    *
    */
    //Test whether word w is in the dictionary
	//If w is a correct word (belongs to the dictionary) then return true, else return false
	//If w is a misspelling then the dictionary and
	//the misspeling list might need to be updated
    //TO IMPLEMENT
	bool testSpelling(string w);


	/** \brief Add a new word w to the dictionary.
    *
    * \return None
    * \note The list of addedWords is also updated.
    *
    */
	//Add a new word w to the dictionary
	//The list of addedWords is also updated
    //TO IMPLEMENT
	void addWord(string w);


	/** \brief Remove all extra added words from the dictionary.
    *
    * \return None
    * \note This function can be called before starting to spell check a new text file.
    *
    */
	//Remove all extra added words from the dictionary
    //This function can be called before starting to spell check a new text file
    //TO IMPLEMENT
	void clean();

	/** \brief Create the log file with the misspellings.
    *
    * \param os ostream object where misspelings are listed.
    * \return None
    * \note The misspellings list is emptied.
    *
    */
	//1. Create the log file with the misspellings
	//2. Empty the misspellings list
	//TO IMPLEMENT
	void createLog(ostream& os);

    private:

    //data members
    HashTable *dictionary; /**< The dictionary */
    int nWords; /**< Number of words stored in the dictionary */
    // number of words stored in the dictionary

    list<Item *> misspellings; /**< Misspellings list */

   //ADD other needed data members


    /** \brief Disabled copy constructor.
    *
    */
   //disable copy constructor
   SpellChecker(const SpellChecker &);


    /** \brief Disabled assignment operator.
    *
    */
   //disable assignment operator
   const SpellChecker & operator=(const SpellChecker &);
};

#endif
