#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string userName, Email, Password;
    string searchName, searchPassword, searchEmail;
    fstream file;
public:
    void login();
    void signup();
    void forgot();
};

int main(){
    temp obj; // Declare an object of the temp class
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sign-up";
    cout<<"\n3- Forget password";
    cout<<"\n4- Exit"<<endl;
    cin>>choice;

    switch(choice){
        case '1':
            obj.login();
            break;
        case '2':
            obj.signup();
            break;
        case '3':
            obj.forgot();
            break;
        case '4':
            return 0;
            break;
        default:
            cout<<"Invalid Selection--!";
    }
    return 0;
}

void temp::signup(){
    cout<<"\nEnter your User Name: ";
    cin.ignore();
    getline(cin, userName); // Add semicolon
    cout<<"\nEnter your Email Address: ";
    getline(cin, Email); // Add semicolon
    cout<<"\nEnter your Password: ";
    getline(cin, Password); // Add semicolon
    file.open("loginData.txt", ios::out|ios::app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}

void temp::login(){
    cout<<"----------Login----------"<<endl;
    cout<<"Enter your User Name :: "<<endl;
    cin.ignore();
    getline(cin, searchName);
    cout<<"Enter Your password :: "<<endl;
    getline(cin, searchPassword); // Add semicolon

    file.open("loginData.txt", ios::in);
    if (!file.is_open()) {
        cout << "File not found or cannot be opened!" << endl;
        return;
    }
    while(getline(file, userName, '*') && getline(file, Email, '*') && getline(file, Password)){
        if(userName == searchName && Password == searchPassword){
            cout<<"\nAccount Login Successful...!";
            cout<<"\nUsername: "<<userName<<endl;
            cout<<"Email: "<<Email<<endl;
            return;
        }
    }
    cout<<"Invalid Username or Password...!";
    file.close();
}

void temp::forgot(){
    cout<<"\nEnter your Username: ";
    cin.ignore();
    getline(cin, searchName);
    cout<<"\nEnter Your Email Address: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file.is_open()) {
        cout << "File not found or cannot be opened!" << endl;
        return;
    }
    bool found = false;
    while(getline(file, userName, '*') && getline(file, Email, '*') && getline(file, Password)){
        if(userName == searchName && Email == searchEmail){
            cout<<"\nAccount Found...!";
            cout<<"\nYour Password: "<<Password<<endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout<<"Account not found...!\n";
    file.close();
}
