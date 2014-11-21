#include <iostream>
#include <string>
#include "decriptor.h"
#include "userinterface.h"
//#include "array/array.h"

using namespace std;

int main()
{
    string TEST = "CREATE TABLE nombre Columna1:32 Columna2:64 Columna3:128";
    userinterface* GUI = new  userinterface();
    decriptor* dkrpt = new decriptor(TEST);
    return 0;
}





