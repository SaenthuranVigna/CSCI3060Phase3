#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include "account.h"
#include "login.h"
#include "miscFunctions.h"
using namespace std;



void login::loginType(vector<string> lType,login session){
    int temp = session.updateSessionCounter();
    string transaction = lType[temp];
    if(transaction == "Login"){
        cout << "Select Session Type: Admin or Standard"<<endl;
        string sessionType = lType[session.updateSessionCounter()];
        if(sessionType == "Admin"){
            session.setLoginType(sessionType);
            adminLogin(lType,session);
        }else if(sessionType == "Standard"){
            session.setLoginType(sessionType);
            standardLogin(lType,session);
        }else{
            exit(0);
        }
    }else{
        cout << "User must be logged in to access these features"<<endl;
        exit(0);
    }
    exit(0);
};



void login::standardLogin(vector<string> lType,login session){
 string  number = lType[session.updateSessionCounter()];
 string password = lType[session.updateSessionCounter()];
 string name = lType[session.updateSessionCounter()];
 string loginType = session.getLoginType();
 if(loginType == "Standard"){
     cout << "Enter Account Number"<< endl;
     session.setANumber(number);
     cout << "Enter Account Password"<< endl;
     session.setAPassword(password);
     cout << "Enter Account Holders Name"<< endl;
     session.setAName(name);
     if(standardVerification(session) == true){
        //Function that will check to see what
        //transaction is being called goes here.
        tChooser(lType,session);
     }else{
        exit(0);
     }

 }else{
     exit(0);
 }
}


void login::adminLogin(vector<string> lType,login session){
 string number = lType[session.updateSessionCounter()];
 string password = lType[session.updateSessionCounter()];
 string loginType = session.getLoginType();
 if(loginType == "Admin"){
     cout << "Enter Account Number"<< endl;
     session.setANumber(number);
     cout << "Enter Account Password"<< endl;
     session.setAPassword(password);
     if(adminVerification(session)==true){
        tChooser(lType,session);
     }else{
        exit(0);
     }

 }else{
     exit(0);
 }

}


bool login::standardVerification(login session){
 //Runs through the db and verifies if the information is matching, returns t/f
    bool verify = false;
    for(int i =0;i<standardAccounts.size();i++){
        if(stoi(session.getANumber())==standardAccounts[i].getAccountNumber()){
            verify = true;
            session.setDbPosition(i);
        }
    }
    if(verify == true){
        if(standardAccounts[session.getDbPosition()].getAccountStatus()=="A"){
            if(session.getAPassword()==standardAccounts[session.getDbPosition()].getAccountPassword()){
                if(session.getAName()==standardAccounts[session.getDbPosition()].getAccountName()){
                return true;}else{
                    cout<< "Error: account holder name does not match"<<endl;
                    return false;

                }
            }else{
                cout<<"Error: password is incorrect"<<endl;
                return false;

            }
        }else{
            cout << "Error: this account is disabled"<<endl;
            return false;
        }
    }else{
        return false;
    }
    return false;
}

bool login::adminVerification(login session){
 //Runs through the db and verifies if the information is matching, returns t/f
    bool verify = false;
    for(int i =0;i<adminAccounts.size();i++){
        if(stoi(session.getANumber())==adminAccounts[i].getAccountNumber()){
            verify = true;
            session.setDbPosition(i);
        }
    }
    if(verify == true){
        if(session.getAPassword()==adminAccounts[session.getDbPosition()].getAccountPassword()){
            return true;
        }
    }else{
        return false;
    }
    return false;
};   


void login::setSessionCounter(int sessionCounter){
    this->sessionCounter = sessionCounter;
}



void login::setDbPosition(int dbPosition){
    this->dbPosition = dbPosition;

}


void login::setLoginType(string lType){
    this->lType = lType;
};

void login::setANumber(string aNumber){
    this->aNumber = aNumber;
};

void login::setAPassword(string aPassword){
    this->aPassword = aPassword;  
};


void login::setAName(string aName){
    this->aName = aName;
};


int login::getSessionCounter(){
    return this->sessionCounter;
}

int login::updateSessionCounter(){
    int temp = getSessionCounter();
    setSessionCounter(this->sessionCounter+1);
    return temp;
}


int login::getDbPosition(){
    return this->dbPosition;

}

string login::getLoginType(){
    return this->lType;
};
string login::getANumber(){
    return this->aNumber;
};
string login::getAPassword(){
    return this->aPassword;
};
string login::getAName(){
    return this->aName;
};











