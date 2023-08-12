#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
int fl = 1;
class faculty{
    public:

void getSchedule(){
    
    fstream data;
data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/allocate.csv", ios::in);
int count=0;
string details,word,l;
vector<string> datav;
while(getline(data,l))
{
    count++;
}
data.close();
data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/allocate.csv", ios::in);

for(int i=0; i<=count; i++)
{
    getline(data,details);
    stringstream s(details);
    while (getline(s, word, ','))
    {
        datav.push_back(word);
    }
} 
data.close();

int length = datav.size();
int i=0;
int flag=0;
string Tech,faculty,status;
cout<<"Enter your name"<<endl;
cin>>faculty;
cout<<"Enter your Technology"<<endl;
cin>>Tech;

    while(i<length){
        if(datav[i+1]==Tech && datav[i+8]==faculty){
        flag =1;
        cout<<"BatchID: "<<datav[i]<<" Technology: "<<datav[i+1]<<" No. Of days: "<<datav[i+2]<<" Start Date: "<<datav[i+3]<<" End Date: "<<datav[i+4]<<" Venue: "<<datav[i+5]<<" Participants: "<<datav[i+6]<< " Month: "<<datav[i+7]<<" Faculty Name: "<<datav[i+8]<<" Status: "<<datav[i+9]<<endl;
        }
        i=i+10;
    }
    if(flag == 0){
        cout<<"Training Schedule not found. Please Enter the correct Name and Technology"<<endl;
    }
    data.close();

}
void updateSession(){
    fstream data;
data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/allocate.csv", ios::in);
int count=0;
string details,word,l;
vector<string> datav;
while(getline(data,l))
{
    count++;
}
data.close();
data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/allocate.csv", ios::in);

for(int i=0; i<=count; i++)
{
    getline(data,details);
    stringstream s(details);
    while (getline(s, word, ','))
    {
        datav.push_back(word);
    }
} 
data.close();

int length = datav.size();
int i=0;
int flag=0;
string Tech,faculty,status;
cout<<"Enter your name"<<endl;
cin>>faculty;
cout<<"Enter your Technology"<<endl;
cin>>Tech;
cout<<"Enter your schedule status"<<endl;
cin>>status;

    while(i<length){
        if(datav[i+1]==Tech && datav[i+8]==faculty){
        flag =1;
        datav[i+9]=status;
        }
        i=i+10;
    }
    if(flag == 0){
        cout<<"Training Schedule not found. Please Enter the correct Name and Technology"<<endl;
    }
    data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/allocate.csv",std::ios::out | std::ios::trunc);

    int x =0;
    while(x<length){
        data<<datav[x]<<","<<datav[x+1]<<","<<datav[x+2]<<","<<datav[x+3]<<","<<datav[x+4]<<","<<datav[x+5]<<","<<datav[x+6]<<","<<datav[x+7]<<","<<datav[x+8]<<","<<datav[x+9]<<"\n";
        x=x+10;
    }
    data.close();
}
};
void facultylogin()
{
    
string userid,password,domain;
cout<<"Enter Your Name: ";
cin>>userid;
cout<<"Enter your Password: ";
cin>>password;
cout<<"Enter your Domain/Technology ";
cin>>domain;

fstream data;
string details,word,l;
vector<string> users;
data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/login.csv", ios::in);
int count=0;
while(getline(data,l))
{
    count++;
}
data.close();
data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/login.csv", ios::in);

for(int i=0; i<=count; i++)
{
    getline(data,details);
    stringstream s(details);
    while (getline(s, word, ','))
    {
        users.push_back(word);
    }
}

int length = users.size();
int i=0;
int flag=0;
faculty obj;
while(i<length)
{
    
    if(userid == users[i] && password == users[i+1] && domain == users[i+2] && users[i+3] == "faculty")
    {
        flag=1;
    }
    i = i+4;
}

if(flag==1)
{
    int choice;
    cout<<"Faculty, Login Successfull"<<endl;
    do{                                      
    cout<<"-----------------SCHEDULE MANAGEMENT-------------------"<<endl;
    cout<<"|                  Select An Option :                 |"<<endl;
    cout<<"|                1. View Schedule :                   |"<<endl;
    cout<<"|            2. Modify Schedule Status :              |"<<endl;
    cout<<"|               3. Exit the application :             |"<<endl;
    cout<<"-------------------------------------------------------"<<endl;

    cin>>choice;
    switch(choice){
        case 1:
            obj.getSchedule();
            flag=0;
            break;
        case 2:
            obj.updateSession();
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
    }while(choice!=3);
}
else
{
    fl++;
    if(fl<=3){
        cout<<"Enter Correct Name / Password / Technology"<<endl;
        cout<<endl;
        facultylogin();
    }
    else{
        cout<<"Login Limit Reached...Exiting the Application"<<endl;

    }
}
}