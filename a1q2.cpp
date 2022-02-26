
/*
 assignment 1 problem 2
 Name: Omar Yossuf
 SID: 900212166
 */
#include <iostream>
#include <fstream>
#include "Header.h"
#define MAX 100
using namespace std;




void account::signup(){
    string user,pass,passc;
    ofstream out;
    out.open("student.txt",ios_base::app);
    ofstream Out;
    Out.open("courses.txt",ios_base::app);
    
    cout<<"please create your username: ";
    cin>>user;
    if(!CheckAccount(user)){
        cout<<"please create your password: ";
        cin>>pass;
        cout<<"please confirm your password: ";
        cin>>passc;
        while(pass!=passc){
            cout<<"passwords do not match!\n please try again: \n please confirm your password: ";
            cin>>passc;
        } out<<user<<"\t"<<pass<<endl;
        Out<<user<<"\t"<<pass<<"\t";
        out.close();
        Out.close();
    } else{
        cout<<"user already exists \n please try again!"<<endl;
        signup();
    }
}

bool account::CheckAccount(string User){
    int j=0;
    allaccounts();
    for(int i=0;i<=x;i++){
        if(User==un[i]){
            j=1;
        }if(j==1){
            break;}
    }if(j==1){
        return true;
    } else{
        return false;
    }
}
bool account::CheckPass(string USER,string PASS){
    for(int i=0;i<=x;i++){
        if(USER==un[i]){
            x=i;
            break;
        }
    }
    if(PASS==pw[x]){
        return true;
    }else{
        return false;
    }
}
void account::allaccounts(){
    
    ifstream in;
    in.open("student.txt");
    while(!in.eof()){
        in>>un[x]>>pw[x];
        x++;
    }
    in.close();

}
bool account::login(){
    string user,pass;
    cout<<"username: ";
    cin>>user;
    while(!CheckAccount(user)){
        cout<<"user not found!! \n please try again: "<<endl;
        cout<<"username: ";
        cin>>user;
    }
    cout<<"password: ";
    cin>>pass;
    while(!CheckPass(user, pass)){
        cout<<"incorrect password! \n please try again: "<<endl;
        cout<<"password: ";
        cin>>pass;
    } return true;
}
bool account::logout(){
    int prs;
    cout<<"to logout press 1 \nto continue press 2"<<endl;
    cin>>prs;
    switch (prs){
        case 1:
            return true;
            break;
        case 2:
            return false;
            break;
        default:
            cout<<"invalid input"<<endl;
            return logout();
    }
}

void account::loggedInPage(){
    do {
        ifstream in;
        in.open("courses.txt");
        while(!in.eof()){
            
        }
        
        
    } while (!logout());
}

int main(){
    account test;
    test.signup();
    if (test.login()){
        cout<<"logged in"<<endl;
        
    }
}


