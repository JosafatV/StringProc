#include "userinterface.h"

UserInterface::UserInterface()
{
     cout << " WELCOME TO:                                                                              " << endl;
     cout << "     _______   ____   _______   _                                                         " << endl;
     cout << "     \   ___| / __/  |  ___  | | |                                                        " << endl;
     cout << "      | |_   / /_    | |   | | | |        ____     ___   __    _   __    _  __    _       " << endl;
     cout << "      |  _|  \__ \   | | _ | | | |       |____|   / __/ / _ \ | |_ \ \  // / _ \ | |_     " << endl;
     cout << "      | |    ___\ \  |_|| ||_| | |___            _\_ \ |  __/ |  _\ \ \// |  __/ |  _\    " << endl;
     cout << "      |_|   /_____/     |_|    |_____|           \___/  \__/  |_|    \_/   \__/  |_|      " << endl;
     cout << "   ______________________________________________________________________________________ " << endl;
     cout << endl;
 }

 closeServers(){
     cout << "CLOSING SERVER . . . " << endl;
     //closeServers();
     Running=false;
     cout << "   _________________________________SERVER CLOSED________________________________________ " << endl;
 }
