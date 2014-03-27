/*
  Name: main.cpp
  Author: Aida Nordman
  Course: TND004, Lab 2
  Description: program to implementing a spell checker
*/


//DO NOT MODIFY THIS FILE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "spellChecker.h"

using namespace std;

/** \brief Display a menu of options.
*
* \return None
*
*/
void menu()
{
    cout << "\n***************************************" << endl;
    cout << "*1. Spell check" << endl;
    cout << "*2. Add new words to dictionay" << endl;
    cout << "*3. Removed added words from dictionary" << endl;
    cout << "*4. Quit" << endl;
    cout << "***************************************" << endl;
}


/** \brief Option 1: spell check a text file.
*
* \param S a SpellChecker object.
* \return None
* \note A log file with the misspelings is created.
*
*/
void spell_check(SpellChecker &S)
{
    string name;

    cout << "File name? ";
    getline(cin, name);

    ifstream textFile(name.c_str());

    if (!textFile)
    {
        cerr << "Text file could not be opened!!" << endl;
        return;
    }

    string word;


    //Read text file and spellcheck each word
    while(textFile >> word)
    {
        S.testSpelling(word);
    }

    name = "log_" + name;

    ofstream logFile(name.c_str());

    //Create log file with misspelings
    S.createLog(logFile);

    //close files
    textFile.close();
    logFile.close();
}



/** \brief Option 2: add extra words to the dictionary.
*
* \param S a SpellChecker object.
* \return None
*
*/
void addNewWords(SpellChecker &S)
{
    string name;

    cout << "File with new words: ";
    getline(cin, name);

    ifstream textFile(name.c_str());

    if (!textFile)
    {
        cerr << "Text file could not be opened!!" << endl;
       return;
    }

    string word;

    //Read text file and add each word to the dictionary
    while(textFile >> word)
    {
        S.addWord(word);
    }

    //close files
    textFile.close();
}



/** \brief main function to test the spell checker
 *
 * Code cannot be modified
 * \author Aida Nordman
 * \date March, 2014
 * \note TND004, Lab 2
 */
int main()
{
    SpellChecker SP;

    const int QUIT = 4;
    int option;

    do
    {
        menu();
        cout << "Option? ";

        cin >> option;
        cin.ignore();

        switch (option)
        {
            case 1: spell_check(SP);
                    break;
            case 2: addNewWords(SP);
                    break;
            case 3: SP.clean(); //remove added words from the dictionary
                    break;
            case 4: break;
           default: cout << "Wrong option!!" << endl;
        }

    } while (option != QUIT);

    return 0;
}
