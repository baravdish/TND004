#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <algorithm>

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


bool isNotAlpha(char c)
{
    return !isalpha(c);
}

void load_dictionary(HashTable &dictionary)
{
    ifstream file("engDict.txt");

    if (!file)
    {
        cerr << "Dictionary file could not be opened!!" << endl;
        exit(1);
    }

    //load the dictionary
    string w;

    while(file >> ws && getline(file, w))
    {
        dictionary.insert(w,0);
    }
}


int main()
{
    HashTable dic(49200, my_hash, 2);

    //1. Load the dictionary
    load_dictionary(dic);

    //Display the hash table used for teh dictionary
    //can take some time!!
    //cout << dic;

    cout << "Load factor = " << fixed << setprecision(2)
         << dic.loadFactor() << endl;

    string name;

    cout << "File name? ";
    getline(cin, name);

    ifstream textFile(name.c_str());

    if (!textFile)
    {
        cerr << "Text file could not be opened!!" << endl;
        return 0;
    }

    string word;

    //Check which words of teh text file are in the dictionary
    while(textFile >> word)
    {
        //remove non-alpha chars
        word.erase(remove_if(word.begin(), word.end(), isNotAlpha), word.end());

        //convert to lower-case letters
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (word == "") continue; //skip any word formed only of punctuation signs

        if (dic.find(word))
            cout << "Found: " << word << endl;
        else
            cout << "Not found: " << word << endl;
    }

    int test_dummy_shit;
    cin>>test_dummy_shit;

    return 0;
}
