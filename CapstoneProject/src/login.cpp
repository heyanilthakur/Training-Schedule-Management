#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include"/Users/AN20449220/Desktop/CapstoneProject/header/Admin.h"
#include"/Users/AN20449220/Desktop/CapstoneProject/header/Faculty.h"

using namespace std;

int main(){
    int choice;
    bool flag=1;
    do{                                      
    cout<<"----------------------LOGIN HERE-----------------------"<<endl;
    cout<<"|                  Select An Option :                  |"<<endl;
    cout<<"|                  1. Login As Admin :                 |"<<endl;
    cout<<"|                 2. Login As Faculty :                |"<<endl;
    cout<<"|               3. Exit the application :              |"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"                   Select a Choice :                   "<<endl;


    cin>>choice;
    switch(choice){
        case 1:
            adminlogin();
            flag=0;
            break;
        case 2:
            facultylogin();
            flag=0;
            break;
        case 3:
            system("exit");
            break;
        default:
            cout<<"Invalid Input..!"<<endl;
            cout<<"Try Again.."<<endl;
            break;
        }
    }while(choice!=3 && flag);
    return 0;
}