#ifndef DECRIPTOR_H
#define DECRIPTOR_H
#include <string>
#include "array/array.h"
using namespace std;

class decriptor
{
public:
    decriptor(string pline);

private:

    //Get the next word of the string??
    string NextWord();

    //???
    int ColNameToIndex(string pName);


    int StrToInt (string ToParse);
    void getCreationArguments ();
    void decript ();

    string line;
    string fileName;
    array<char*> cNames;
    array<int> cSais;
    int RegSaiz;

};

#endif // DECRIPTOR_H
