
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
        
        out.close();
        
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
        cout<<"user not found!! \n to try again press 1 to signup press 2"<<endl;
        int prs;
        cin>>prs;
        if(prs==2){signup(); break;}else if(prs==1){
        cout<<"username: ";
            cin>>user;}
        else{cout<<"invalid input"<<endl;}
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



bool account::checkCourse(int prs){
    if(prs==3||prs==5||prs==7){
        return true;
    } else if(prs<=10){
        return true;
    }else{
        cout<<"invalid input"<<endl;
        return false;
    }
}
bool account::NumOfCredits(){
    allaccounts();
    unsigned int num=0;
    int prs;
    
    string crs[10];
    string choices[10]={"cs1","cs2","cs2Lab","phys1","phys1Lab","phys2","phys2Llab","engl0210","rhet1010","core1010"};
    cout<<"select the course you want to add: "<<endl;
    cout<<"1: cs 1\n2: cs 2\n3: cs 2 lab\n4: phys 1\n5:phys 1 lab\n6: phys 2\n7: phys 2 lab\n8: engl 0210\n9: rhet 1010\n10: core 1010"<<endl;
    cin>>prs;
    if(checkCourse(prs-1)){
    ofstream out;
    int k=0;
    for (int i=0;i<10;i++){
        if(crs[i]==choices[prs-1]){
            k=1;
            cout<<"you can't add the same course more than one time!"<<endl;
            break;
        }
            }
    if(k!=1){
    crs[x]=choices[prs-1];
    
        if(prs==3||prs==5||prs==7){
            num++;
        } else if(prs<=10){
            num+=3;
        }
        
    out.open("courses.txt", ios_base::app);
        out<<un[x]<<crs[x]<<"\t";
        cout<<"to add another course press 1 to exit press any other number"<<endl;
        cin>>prs;
        if(prs==1){
            cout<<"select the course you want to add: "<<endl;
            cout<<"1: cs 1\n2: cs 2\n3: cs 2 lab\n4: phys 1\n5:phys 1 lab\n6: phys 2\n7: phys 2 lab\n8: engl 0210\n9: rhet 1010\n10: core 1010"<<endl;
            cin>>prs;
            if(checkCourse(prs-1)){
            
            int k=0;
            for (int i=0;i<x;i++){
                if(crs[i]==choices[prs-1]){
                    k=1;
                    cout<<"you can't add the same course more than one time!"<<endl;
                    break;
                }
                    }
            if(k!=1){
            crs[x]=choices[prs-1];
                out<<crs[x]<<"\t";
                if(prs==3||prs==5||prs==7){
                    num++;
                } else if(prs<=10){
                    num+=3;
                }
            } else {
            }
            }}out<<"remaning credit hours: "<<18-num<<endl;
    }
    out.close();
        
    }
    
    if(num<=18){
        return true;
    } else{
        return false;
    }
    }

int main(){
    account test;
    int prs;
    cout<<"to sign up press 1\nto login press 2 \nto exit press 3"<<endl;
    cin>>prs;
    if (prs==1){
        test.signup();
        cout<<"to login press 1"<<endl;
        cin>>prs;
        if (prs == 1) {
            if (test.login()){
                while(test.NumOfCredits()){
                    if(test.logout()){
                        break;
                    }
                }
                
            }
        }else return 0;
    }
    else if(prs==2){
    if (test.login()){
        while(test.NumOfCredits()){
            if(test.logout()){
                break;
            }
        }
        
    }
        
    }else if (prs==3){return 0;}
    else{
        cout<<"invalid input"<<endl;
        main();
    }
    return 0;
}


