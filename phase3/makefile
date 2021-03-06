test: main.o account.o login.o miscFunctions.o accDelete.o logout.o paybill.o changeplan.o
	g++ main.o account.o login.o miscFunctions.o accDelete.o logout.o paybill.o changeplan.o -o test

main.o: main.cpp
	g++ -c main.cpp
login.o: login.cpp
	g++ -c login.cpp
account.o: account.cpp
	g++ -c account.cpp
miscFunctions.o: miscFunctions.cpp
	g++ -c miscFunctions.cpp
accDelete.o: accDelete.cpp
	g++ -c accDelete.cpp
logout.o: logout.cpp
	g++ -c logout.cpp
paybill.o: paybill.cpp
	g++ -c paybill.cpp	
changeplan.o: changeplan.cpp
	g++ -c changeplan.cpp
clean:
	rm *.o test 