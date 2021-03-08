#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "transfer.h"
#include "login.h"
#include "account.h"
#include "miscFunctions.h"

using namespace std;


transfer::transfer() {}

void transfer::setSession(login session) {

    if (session.getLoginType() == "Admin") {
        this->adminTransaction = true;
    }
    else {
        this->adminTransaction = false;
    }
}

void transfer::setAccountFrom(string accountNum, string name) {
    int accountNumber;
    string holderName;

    if (holderName != "") {
        cout << "Please enter the account holder's name: " << endl;
        holderName = name;
        cout << name << endl;

        // Seeing if the name exists in the standardAccount vector
        bool foundName = false;
        for (int i = 0; i < standardAccounts.size(); i++) {
            if (holderName == standardAccounts[i].getAccountName()) {
                foundName = true;
                cout << "Valid account holder" << endl;
            }
        }

        if (foundName == false) {
            cout << "Error: name not found" << endl;
        }

        cout << "Please enter the account number: " << endl;
        accountNumber = stoi(accountNum);
        cout << accountNumber << endl;

        // Seeing if the account exists in the standardAccount vector
        bool foundNum = false;
        for (int i = 0; i < standardAccounts.size(); i++) {
            if ((holderName == standardAccounts[i].getAccountName()) &&
                (accountNumber == standardAccounts[i].getAccountNumber()) &&
                foundName == true) {
                foundNum = true;
                this->accountFrom = &standardAccounts[i];
                cout << "Account number valid" << endl;
            }
        }

        if (foundNum == false) {
            cout << "Error: account not found under holder's name" << endl;
        }
    }
    else {
        cout << "Please enter the account number: " << endl;
        accountNumber = stoi(accountNum);
        cout << accountNumber << endl;

        // Seeing if the account exists in the standardAccount vector
        bool found = false;
        for (int i = 0; i < standardAccounts.size(); i++) {
            if (accountNumber == standardAccounts[i].getAccountNumber()) {
                found = true;
                this->accountFrom = &standardAccounts[i];
                cout << "Account number valid" << endl;
            }
        }

        if (found == false) {
            cout << "Error: Account not found." << endl;
        }
    }
}

void transfer::setAccountTo(string accountNum) {

    int accountNumber;

    cout << "Please enter the account number: " << endl;
    accountNumber = stoi(accountNum);
    cout << accountNumber << endl;

    // Seeing if the account exists in the standardAccount vector
    bool found = false;
    for (int i = 0; i < standardAccounts.size(); i++) {
        if (accountNumber == standardAccounts[i].getAccountNumber()) {
            found = true;
            this->accountFrom = &standardAccounts[i];
            cout << "Account number valid" << endl;
        }
    }
    
    if (found == false) {
        cout << "Error: Account not found" << endl;
    }
}

void transfer::setAmount(string setAmount) {
    float amount;

    cout << "Please enter the amount to transfer: " << endl;
    cout << setAmount << endl;
    amount = stof(setAmount);

    if (adminTransaction == true  && amount > 0.00) {
        this->transferAmount = amount;
        cout << "Valid amount" << endl;
    }
    else if (adminTransaction == false && amount > 0.00 && amount < 1000.00) {
        this->transferAmount = amount;
        cout << "Valid amount" << endl;
    }
    else {
        cout << "Error: Cannot transfer set amount." << endl;
    }
}

void transfer::conductTransfer(vector<string> lType, login session) {

    cout << "Transfer selected" << endl;
    //cout << lType[session.getSessionCounter()] << endl;

    setSession(session);
    
    if (lType[session.getSessionCounter()] != "cancelTransfer") {
        if (adminTransaction == true) {
            string name = lType[session.updateSessionCounter()];
            string account = lType[session.updateSessionCounter()];
            setAccountFrom(account, name);
        }
        else if (adminTransaction == false){
            setAccountFrom(lType[session.updateSessionCounter()], "");
        }
    }

    if (lType[session.getSessionCounter()] != "cancelTransfer") {
        setAccountTo(lType[session.updateSessionCounter()]);
    }

    if (lType[session.getSessionCounter()] != "cancelTransfer") {
        setAmount(lType[session.updateSessionCounter()]);
    }

    if (lType[session.getSessionCounter()] != "cancelTransfer") {
        if (accountTo->getAccountNumber() != 0 && accountFrom->getAccountNumber() != 0) {
            float accountFromBalance = accountFrom->getBalance();
            float accountToBalance = accountTo->getBalance();

            if ((accountFromBalance - transferAmount) > 0.00 && (accountToBalance + transferAmount) > 0.00) {
                accountFrom->setBalance(accountFromBalance - transferAmount);
                accountTo->setBalance(accountToBalance + transferAmount);
                // saveLogs();
                cout << "Transfer successful" << endl;
            }
            else {
                cout << "Transfer unsuccessful" << endl;
            }
        }
        else {
            cout << "Transfer unsuccessful" << endl;
        }

        tChooser(lType,session);
    }
    else {
        cout << lType[session.getSessionCounter()] << endl;
        session.updateSessionCounter();
        tChooser(lType,session);
    }
}

/*
void transfer::saveLogs() {
    FILE file = "transfer_" + transactionNumber + ".etf";
    fstream stream;
    stream.open(file, ios::out);
    if (!stream) { exit(1); }
    else {
        stream << "02_" << accountFrom.getAccountName() << "_"
               << accountFrom.getAccountNumber() << "_-" << transferAmount
               << "___"
               
               << endl

               << "02_" << accountTo.getAccountName() << "_"
               << accountTo.getAccountNumber() << "_+" << transferAmount
               << "___" << endl;
    }
    close(file);
}
*/