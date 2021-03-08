#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "account.h"

using namespace std;

class deposit {
    public:
        account transactionAccount;
        string loginType, aName;
        int aNumber;
        float amount;

        void saveLog();

        deposit();
        void makeDeposit();
        bool setAccountName(string aName, vector<account> type);
        bool setAccountNumber(int aNumber, vector<account> type);
        void setAmount(float amount);
};

extern vector<account> adminAccounts;
extern vector<account> standardAccounts;

#endif