#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "disable.h"
#include "login.h"
#include "account.h"
#include "miscFunctions.h"

using namespace std;


disable::disable() {}

void disable::setSession(login session) {

    if (session.getLoginType() == "Admin") {
        this->adminTransaction = true;
    }
    else {
        this->adminTransaction = false;
    }
}

void disable::setSelectedAccount(string accountNum, string name) {
    if (adminTransaction == true) {
        string holderName;
        int accountNumber;

        cout << "Please enter the account holder's name: ";
        holderName = name;

        // Seeing if the name exists in the standardAccount vector
        bool foundName = false;
        for (int i = 0; i < standardAccounts.size(); i++) {
            if (holderName == standardAccounts[i].getAccountName()) {
                foundName = true;
                cout << "Name valid" << endl;
            }
        }

        if (foundName == false) {
            cout << "Error: name not found" << endl;
        }

        cout << "Please enter the account number you wish to disable: ";
        accountNumber = stoi(accountNum);

        // Seeing if the account exists in the standardAccount vector
        bool foundNum = false;
        for (int i = 0; i < standardAccounts.size(); i++) {
            if ((holderName == standardAccounts[i].getAccountName()) &&
                (accountNumber == standardAccounts[i].getAccountNumber()) &&
                foundName == true) {
                foundNum = true;
                this->selectedAccount = standardAccounts[i];
                cout << "Account number valid" << endl;
            }
        }

        if (foundNum == false) {
            cout << "Error: Account not found under holder's name" << endl;
        }
    }
    else {
        cout << "Error: You can only disable an account in admin mode" << endl;
    }
}

void disable::disableAccount(vector<string> lType, login session) {

    cout << "Disable selected" << endl;

    setSession(session);

    if (lType[session.getSessionCounter()] != "cancelDisable") {
        string name = lType[session.updateSessionCounter()];
        string account = lType[session.updateSessionCounter()];
        setSelectedAccount(account, name);
    }

    if (lType[session.getSessionCounter()] != "cancelDisable") {
        if (selectedAccount.getAccountNumber() != 0 && selectedAccount.getAccountStatus() == "A" && adminTransaction == true) {
            selectedAccount.setAccountStatus("D");
            // saveLogs();
            cout << "Account successfully disabled" << endl;
        }
        else {
            cout << "Account could not be disabled" << endl;
        }
        
        //cout << lType[session.getSessionCounter()] << endl;
        tChooser(lType,session);
    }
    else {
        cout << lType[session.getSessionCounter()] << endl;
        session.updateSessionCounter();
        tChooser(lType,session);
    }
}

/*
void disable::saveLogs() {
    FILE file = "disable_" + transactionNumber + ".etf";
    fstream stream;
    stream.open(file, ios::out);
    if (!stream) { exit(1); }
    else {
        stream << "07_" << selectedAccount.getAccountName() << "_"
               << selectedAccount.getAccountNumber() << "_00000.00"
               << "__D" << endl;
    }
    close(file);
}
*/