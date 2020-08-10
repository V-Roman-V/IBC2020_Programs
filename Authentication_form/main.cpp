#include <iostream>
#include <string>
using namespace std;

/*
To run this program, paste into the .replit file this text:
	
	run = "clang++-7 -pthread -std=c++17 -o Authentication_form/main Authentication_form/main.cpp \n ./Authentication_form/main"

And click the run button
*/
const string login = "admin";
const string password = "password";

int main(){
	cout<<"Enter login and password"<<endl;
	string log,pass;
	for(int i=0;i<3;i++){
		cout<<"login: ";
		cin>>log;
		cout<<"password: ";
		cin>>pass;
		if(pass.compare(password)==0 && log.compare(login)==0){
			cout<<"Access has granted"<<endl;
			return 0;
		} else if(i<2){
			cout<<"please enter your login and password again. You have "<<2-i<<" attempts left"<<endl;
		}
	}
	cout<<"Acces has restricted"<<endl;
	return 0;
}