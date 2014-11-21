#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "array/array.h"
#include "decriptor.h"
<<<<<<< HEAD

using namespace std;
=======
using namespace std;


//globales principales
string fileName = "";
array<char*> cNames();
array<int> cSais ();
int RegSaiz = 0;

//globales temporales
string line;
array<char*> tNames();
array<char*> tValue ();
>>>>>>> 1ceb28af32a8ed88ad96055866be1ce4c21733f3

decriptor::decriptor(string pline) {
    this->line = pline;
    this->cNames = array <char*>(255);
    this->cSais = array <int > (255);
    this->RegSaiz = 0;
    this->fileName = "";
    decript();
}

string decriptor::NextWord() {
    string bhla = "";
<<<<<<< HEAD

    int cut = this->line.find(' ');
    bhla = this->line.substr(0, cut);
    this->line =  this->line.substr(cut+1, this->line.length());
=======
    int cut = line.find(' ');
    bhla = line.substr(0, cut);
    line = line.substr(cut+1, line.length());
    cout << bhla << endl;
>>>>>>> 1ceb28af32a8ed88ad96055866be1ce4c21733f3
    return bhla;
}


string charToStr(char* pChar){
    string toReturn = "";
    toReturn.assign(pChar , sizeof(pChar));
    return toReturn;
}


int decriptor::ColNameToIndex(string pName) {
    string ColName = "";
    int Index = -1;
    for (int i = 0; i < cNames.getLenght(); i++) {
        ColName = charToStr(cNames[i]);
        if (ColName.compare(pName)) {
            Index=i;
            break;
        }
    }
    return Index;
}

int decriptor::StrToInt (string ToParse) {
    int number  = atoi(ToParse.c_str());
    return number;
}

void decriptor::getCreationArguments () {
    string col = "";
    int split = 0;
    int cut = 0;
    int saiz = 0;
    while (line.length()>1) { // ~
        cut = line.find(' ');
        if (0==line.substr(0, cut).compare("RAID")) {
            break;
        }
        else {
            split = line.find(':');
            col = line.substr(0, split);
            saiz = StrToInt(line.substr(split+1, cut-(split-1))); //~ substr is not reliable
            line = line.substr(cut+1, line.length());

<<<<<<< HEAD
    cut = this->line.find(' ');
    while (line != "") {
        split = this->line.find(":");
        col = this->line.substr(0, split);
        saiz = StrToInt(this->line.substr(split+1, cut-(split-1))); //~ substr is not reliable
        this->line = this->line.substr(cut+1, this->line.length());

        RegSaiz += saiz;
        cNames.insert(0, const_cast<char*>( col.c_str()));
        cSais.insert(0, saiz);
=======
            RegSaiz += saiz;
            tNames().insert(0, col);
            tValues().insert(0, saiz);
        }
    }
}

void decriptor::getArguments () {
    string col = "";
    int split = 0;
    int cut = 0;
    string val = "_";
    while (line.length()>1) { // ~
        cut = line.find(' ');
            split = line.find(':');
            col = line.substr(0, split);
            val = StrToInt(line.substr(split+1, cut-(split-1))); //~ substr is not reliable
            line = line.substr(cut+1, line.length());

            RegSaiz += saiz;
            tNames().insert(0, col);
            tValues().insert(0, saiz);
>>>>>>> 1ceb28af32a8ed88ad96055866be1ce4c21733f3
    }
}

void decriptor::decript () {

    string fName = "";
    string cName = "";
    string uName = "";

    string firstWord = NextWord();
    if (firstWord == "CREATE") {
        if (NextWord() == "TABLE") {
            fileName = NextWord();
            getCreationArguments(); //RegSize, cSais, cNames
            if (NextWord()=="USING"){
                if (NextWord()=="RAID"){
                    string RAID = "0";
                    //filesystem->creteNewFile(&RegSize ,&cSais, &cNames ,&fileName, &RAID);
                }else{
                    cout << "No monkeys alowed" <<endl;
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
            //filesystem->writeNewLineToFile(&fName, &cData, &cPos);test
        }
    }
    if (firstWord == "SELECT") {
        cName = NextWord();
        if (NextWord()=="FROM") {
            fname = NextWord();
            if (cName == "*") {
                //filesystem->readFromFile(&NextWord(), &cNames());
            } else {
                //filesystem->readFromFile(&fileName , &ColNameToIndex(cName), &1);
            }
        }
    }
    if (firstWord == "UPDATE") {
        fName = NextWord();
        if (NextWord() == "SET") {
            cName = NextWord();
        } if (NextWord() == "TO") {
            getArguments();
            //filesystem->update("&Daniel", &fName, 1 , 1);
        }
    }
<<<<<<< HEAD
    if (NextWord() == "DELETE") {
        if (NextWord() == "FROM") {
=======
    if (firstWord == "DELETE") {
        if (NextWord() = "FROM") {
>>>>>>> 1ceb28af32a8ed88ad96055866be1ce4c21733f3
            fName = NextWord();
            cName = NextWord();
            uName = NextWord();
            //filesystem->deleteData(&fName , cName" , uName);
        }
    }
    if (firstWord == "CREATE"){
        if (NextWord() == "INDEX"){
            if (NextWord() == "ON"){
                fName = NextWord();
                cName = NextWord();
                cout << "NOT YET IMPLEMENTED" << endl;
            }
        }
    }
    if (firstWord == "COMPRESS"){
        if (NextWord() == "TABLE"){
            fName = NextWord();
            cout << "NOT YET IMPLEMENTED" << endl;
        }
    }
    if (firstWord == "BACKUP"){
        if (NextWord() == "TABLE"){
            fName = NextWord();
            //filesystem->backUpFile(NextWord());
        }
    }
    if (firstWord == "RESTORE"){
        if (NextWord() == "TABLE"){
            fName = NextWord();
            //filesystem->restoreFile(NextWord());
        }
    }
    if (firstWord == "CREATE") {
        if (NextWord()== "USER"){
            string pass = "";
            uName = NextWord();
            if (NextWord() == "PASSWORD"){
            pass = NextWord();
            //filesystem->createUser(&uName, &pass);
            }
        }
    }
    if (firstWord == "DROP"){
        if (NextWord() == "USER") {
            uName = NextWord();
            //filesystem->dropUser(uName);
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

