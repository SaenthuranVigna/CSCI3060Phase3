#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "account.h"

using namespace std;

class create {
    public:
        account acc;
        float balance;
        string aName, loginType;

        void saveLog();
        
        void Create(vector<string> lType,login session);
        void setAccountName(string aName, string loginType);
        bool setBalance(vector<string> lType, float balance);
        void createAccount(vector<string> lType, login session);
};

extern vector<account> adminAccounts;
extern vector<account> standardAccounts;

#endif