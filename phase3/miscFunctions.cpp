#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "miscFunctions.h"
#include "account.h"
#include "login.h"
#include "accDelete.h"
#include "logout.h"
#include "paybill.h"
#include "changeplan.h"

void tChooser(vector<string> lType,login session){
	if(session.getLoginType()=="Standard"){
		string transaction = lType[session.updateSessionCounter()];
		cout<<transaction<<endl;
		if(transaction == "Withdrawal"){
		}else if(transaction == "Transfer"){

		}else if(transaction=="Paybill"){
			payBill p;
			p.paybill(lType,session);
		}else if(transaction == "Deposit"){
			
		}else if(transaction == "Logout"){
			
		}else if(transaction == "Create" || transaction == "Delete" || transaction == "Disable" || transaction == "Changeplan"){
			cout<<"User lacks permissions to access this function"<<endl;

		}else{
			exit(0);
		}

	}else if(session.getLoginType()=="Admin"){
		int temp = session.updateSessionCounter();
		string transaction = lType[temp];
		if(transaction == "Create"){
			//callCreate
		}else if(transaction == "Delete"){

			accDelete delAcc;
			delAcc.deleteAccount(lType,session,delAcc);
			

		}else if(transaction=="Paybill"){
			payBill p;
			p.paybill(lType,session);
		}else if(transaction == "Disable"){
			
		}else if(transaction == "Changeplan"){
			changePlan c;
			c.ChangePaymentType(lType,session);
			
		}else if(transaction == "Logout"){
			logout account;
			account.accLogout(lType,session);
			


		}else{
			exit(0);
		}
	}
};


