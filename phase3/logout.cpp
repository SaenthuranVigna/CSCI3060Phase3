#include <string>
#include <cstdlib>
#include <vector>
#include "logout.h"
#include "login.h"
#include "account.h"

using namespace std;

void logout::accLogout(vector<string> lType,login session){
<<<<<<< HEAD
    if (lType[session.getSessionCounter()+1] != "") {
        session.loginType(lType,session);
        cout << "Logout successful" << endl;
    }
    else {
        cout << "Logout successful" << endl;
        exit(0);
    }
=======
	cout <<"Logout successful"<<endl;
    session.loginType(lType,session);
>>>>>>> 55c163682c03918132e75ebc333d18b45cf17c70
}


// void logout::saveLog() {
//     FILE file = "logoutLogs.etf";
//     fstream stream;
//     stream.open(file, ios::out);
//     if (!stream) { exit(1); }
//     else {
//         stream << "00_" << loginType << transactionAccount.getAccountName() 
//                << transactionAccount.getAccountNumber() << amount << endl;
//     }
//     close(file);
// }