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

    int cut = this->line.find(' ');
    bhla = this->line.substr(0, cut);
    this->line =  this->line.substr(cut+1, this->line.length());
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

    cut = this->line.find(' ');
    while (line != "") {
        split = this->line.find(":");
        col = this->line.substr(0, split);
        saiz = StrToInt(this->line.substr(split+1, cut-(split-1))); //~ substr is not reliable
        this->line = this->line.substr(cut+1, this->line.length());

        RegSaiz += saiz;
        cNames.insert(0, const_cast<char*>( col.c_str()));
        cSais.insert(0, saiz);
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
        if (NextWord() == "FROM") {
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

