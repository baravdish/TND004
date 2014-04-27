#include "spellChecker.h"

#include <fstream>
#include <algorithm>
#include <cctype>
#include <iomanip>

/** \brief Hash function for English words
*
* \note Polynomial accumulation is used. See pag. 213 of course book.
* \param s a string (word).
* \param tableSize an integer representing the size of the hash table.
* \return unsigned int representing the hash value of s (overlow is allowed).
*
*/
//Hash function for English words
//Polynomial accumulation
//the Horner's rule is used to compute the value
//See pag. 213 of course book
unsigned my_hash(string s, int tableSize)
{
    unsigned hashVal = 0;

    for(int i= 0; i < s.length(); i++)
        hashVal= 37 * hashVal + s[i];

    hashVal %= tableSize;

    return hashVal;
}


bool isNotAlpha(char c)
{
    return !isalpha(c);
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS

//Constructor
//Text file fileName should contain a dictionary with n words
//TO IMPLEMENT
SpellChecker::SpellChecker(string fileName, int n)
{
	nWords = n;
	const int MAX_LOAD = 2;
    dictionary = new HashTable(n, my_hash, MAX_LOAD);	// storleken på hashtable = 0...för att constructor kanske är fel...
	ifstream file(fileName);
	string w;

    if (!file)
    {
        cerr << "Dictionary file could not be opened!!" << endl;
        exit(1);
    }

    while(file >> ws && getline(file, w))
    {
        dictionary->insert(w,0);
    }
}


//Destructor
//TO IMPLEMENT
SpellChecker::~SpellChecker()
{
   //ADD CODE

   cout << "** Spell Checker Destructor" << endl;
}


//Test whether word w is in the dictionary
//If w is a correct word (belongs to the dictionary) then return true, else return false
//If w is a misspelling then the dictionary and
//the misspeling list might need to be updated
//TO IMPLEMENT
bool SpellChecker::testSpelling(string w)
{
    //remove non-alpha chars
    w.erase(remove_if(w.begin(), w.end(), isNotAlpha), w.end());

    //convert to lower-case letters
    transform(w.begin(), w.end(), w.begin(), ::tolower);

    if (w == "") return true; //case of a word consisting only of punctuation signs

    //ADD CODE
    return false;
}


//Add a new word w to the dictionary
//The list of addedWords is also updated
//TO IMPLEMENT
void SpellChecker::addWord(string w)
{
    //ADD CODE
}


//Remove all extra added words from the dictionary
//This function can be called before starting to spell check a new text file
//TO IMPLEMENT
void SpellChecker::clean()
{
    //ADD CODE
}


//1. Create the log file with the misspellings
//2. Empty the misspellings list
//TO IMPLEMENT
void SpellChecker::createLog(ostream& os)
{
    os << "*** LIST OF MISSPELLINGS" << endl;
    os << "=========================" << endl;

    //ADD CODE
}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */
