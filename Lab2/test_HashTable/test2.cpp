#include <iostream>
#include <iomanip>

#include "hashTable.h"

using namespace std;


/** \brief Hash function for English words
*
* \note Polynomial accumulation is used. See pag. 213 of course book.
* \param s a string (word).
* \param tableSize an integer representing the size of the hash table.
* \return unsigned int representing the hash value of s (overlow is allowed).
* \note The misspellings list is emptied.
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



int main()
{
    HashTable table(5, my_hash, 1);

    table.insert("Aida");
    table.insert("Lucas");
    table.insert("Pierangelo");
    table.insert("Kenneth");
    table.insert("Jonas");
    table.insert("Britt");

    cout << "** Insert" << endl << endl;
    cout << table << endl << endl;

    if (! table.find("Aida"))
        table.insert("Aida");
    else
        cout << "Aida is already in the table!" << endl;

    cout << "** Find" << endl << endl;

    const Item *p = table.find("Jonas");
    if (p) cout << *p << endl << endl;

    cout << "** Remove" << endl << endl;

    if (table.remove("Jonas"))
        cout << "Remove successfull!!" << endl << endl;

    p = table.find("Jonas");
    if (p)
        cout << *p;
    else
        cout << "Jonas not found." << endl << endl;

    //cout << table << endl << endl;

    table.insert("Jesper");
    table.insert("Rikard");
    table.insert("Ian");
    table.insert("Sawn");
    table.insert("Robert");
    table.insert("Hans");

    cout << table << endl << endl;

    return 0;
}
