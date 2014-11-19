#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "array/array.h"
#include "decriptor.h"
using namespace std;


//globales principales
string fileName = "";
array<char*> cNames();
array<int> cSais ();
int RegSaiz = 0;

//globales temporales
string line;


decriptor::decriptor(string pline) {
    line = pline;
    decript();
}

string decriptor::NextWord() {
    string bhla = "";
    int cut = line.find(' ');
    line = test.substr(0, cut);
    test = test.substr(cut+1, line.length());
    return bhla;
}

int decriptor::ColNameToIndex(string pName) {
    string ColName = "";
    int Index = -1;
    for (int i = 0; i<cNames.getLenght(); i++) {
        ColName = cNames[i];
        if (0==cNames.compare(pName)) {
            Index=i;
            break;
        }
    }
    return Index;
}

int decriptor::StrToInt (string ToParse) {
    string unit;
    int unyt = 0;
    int number = 0;

    while (ToParse!=("")) {
    unit = ToParse.substr(0, 1);
    if (0==unit.compare("0")) {
        unyt = 0;
    }
    if (0==unit.compare("1")) {
        unyt = 1;
    }
    if (0==unit.compare("2")) {
        unyt = 2;
    }
    if (0==unit.compare("3")) {
        unyt = 3;
    }
    if (0==unit.compare("4")) {
        unyt = 4;
    }
    if (0==unit.compare("5")) {
        unyt = 5;
    }
    if (0==unit.compare("6")) {
        unyt = 6;
    }
    if (0==unit.compare("7")) {
        unyt = 7;
    }
    if (0==unit.compare("8")) {
        unyt = 8;
    }
    if (0==unit.compare("9")) {
        unyt = 9;
    }
    ToParse = ToParse.substr(1, ToParse.length());
    number = (number*10);
    number += unyt;
    }
    return number;
}

void decriptor::getCreationArguments () {
    string col = "";
    int split = 0;
    int cut = 0;
    int saiz = 0;

    cut = line.find(' ');
    while(0!=line.substr(0, cut).compare("RAID")) {
    split = line.find(':');
    col = line.substr(0, split);
    saiz = StrToInt(line.substr(split+1, cut-(split-1))); //~ substr is not reliable
    line = line.substr(cut+1, line.length());

    RegSaiz += saiz;
    cNames().insert(0, col);
    cSais().insert(0, saiz);
    }
}

void decriptor::decript () {

    string fName = "";
    string cName = "";
    string uName = "";

    firstWord = NextWord();
    if (firstWord == "CREATE") {
        if (NextWord() == "TABLE") {
            fileName = NextWord();
            getCreationArguments(); //RegSize, cSais, cNames
            if (NextWord()=="USING"){
                if (NextWord()=="RAID"){
                    string RAID = "0";
                    //filesystem->creteNewFile(&RegSize ,&cSais, &cNames ,&fileName, &RAID);
                }
            } else {
                //filesystem->createNewFile(&RegSize ,&cSais, &cNames ,&fileName);
            }
        }
        if (NextWord() == "USER") {
            uName = NextWord();
            if (NextWord() == "PASSWORD") {
                //filesystem->createUser(uName, NextWord());
            }
        }
    }
    if (firstWord == "INSERT") {
        if (NextWord() == "INTO"){
            fName = NextWord();
            //filesystem->writeNewLineToFile(&fName, &cData, &cPos);
        }
    }
    if (firstWord == "SELECT") {
        cName = NextWord();
        if (cName == "*") {
            //filesystem->readFromFile(&NextWord(), &cNames());
        } else {
            //filesystem->readFromFile(&fileName , &ColNameToIndex(cName), &1);
        }
    }
    if (firstWord == "UPDATE") {
        fName = NextWord();
        if (NextWord() == "SET") {
            cName = NextWord();
        } if (NextWord() == "TO") {

        }
        //filesystem->update("&Daniel", &fName, 1 , 1);
    }
    if (NextWord() == "DELETE") {
        if (NextWord() = "FROM") {
            fName = NextWord();
            //filesystem->deleteData(&fName , "Nombre" , "Luis");
        }
    }
    if (firstWord == "CREATE"){
        if (NextWord() == "INDEX"){
            if (NextWord() == "ON"){
                cout << "NOT YET IMPLEMENTED" << endl;
            }
        }
    }
    if (firstWord == "COMPRESS"){
        if (NextWord() == "TABLE"){
            cout << "NOT YET IMPLEMENTED" << endl;
        }
    }
    if (firstWord == "BACKUP"){
        if (NextWord() == "TABLE"){
            //filesystem->backUpFile(NextWord());
        }
    }
    if (firstWord == "RESTORE"){
        if (NextWord() == "TABLE"){
            //filesystem->restoreFile(NextWord());
        }
    }
    if (firstWord == "DROP"){
        if (NextWord() == "USER") {
            //filesystem->dropUser(NextWord());
        }
    }
    string permit = "";
    if (firstWord == "GRANT"){
        permit = NextWord();
        if (NextWord() == "ON") {
            fName = NextWord();
            if (NextWord() == "TO") {
                uName = NextWord();
                //filesystem->grantPermit(&fName, &permit, &uName);
            }
        }
    }
    if (firstWord == "REVOKE"){
        permit = NextWord();
        if (NextWord() == "ON") {
            fName = NextWord();
            if (NextWord() == "TO") {
                uName = NextWord();
                //filesystem->grantPermit(&fName, &permit, &uName);
            }
        }
    }
}

