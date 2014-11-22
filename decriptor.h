#ifndef DECRIPTOR_H
#define DECRIPTOR_H

#include <string>
#include "array/array.h"
using namespace std;

class decriptor
{
public:
    /*!
     * \brief decriptor sets the logic to decript a command line taken from the terminal into orders FSQL can process
     * \param pline the command line
     *
     * FSQL receives commands via a terminal window. These commands have to be processed into orders that the logic inside FSQL can process
     */
    decriptor(string pline);

private:
    
    string line;
    string fileName;
    array<char*> cNames;
    array<int> cSais;
    int RegSaiz;
    
    /*!
     * \brief NextWord the next word before " " in the command line
     * \return the word
     *
     * In order to process the command line each word has to be compared individually to check syntaxis.
     * This function "pops" the first word before " " in a global variable and returns it.
     * Once the word is separated from the sentence it can be compared
     */
    string NextWord();

    /*!
     * \brief ColNameToIndex turn a column's name to it's respective index
     * \param pName the column's name
     * \return the column's index in the array
     *
     * Some of the logic in FSQL requires an index. Instead of a name, in order to ease the main logic into turning a column's name to it's respective index
     * the class uses it's global cNames (an array with the column's names) and looks for the respective index.
     */
    int ColNameToIndex(string pName);

    /*!
     * \brief StrToInt turns a string into an int
     * \param ToParse the string
     * \return the int
     *
     * Since the command line is a string it was necessary to create a function to turn chars into integers. This is it.
     * It takes the numerical string and returns the value it represents as an int
     */
    int StrToInt (string ToParse);

    /*!
     * \brief getCreationArguments gets the arguments to create a table
     *
     * This function not only gets the values to create the table but it also sets the globals required by the function ColNameToIndex
     */
    void getCreationArguments ();

    /*!
     * \brief getArguments gets the arguments for inserting
     *
     * This function creates temporary arrays for the FSQL logic, it is similar to getCreationArguments but it doesn't set globals
     */
    void getArguments ();

    /*!
     * \brief decript turns the command line into orders
     *
     * Here the words are passed through several IF clauses with the purpose of checking syntaxis.
     * It calls all the other functions and is called by the constructor
     */
    void decript ();
};

#endif // DECRIPTOR_H
