#include <string>
#include <cstdlib>
#include <vector>
#include "logout.h"
#include "login.h"
#include "account.h"

using namespace std;

void logout::accLogout(vector<string> lType,login session){
    session.loginType(lType,session);
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