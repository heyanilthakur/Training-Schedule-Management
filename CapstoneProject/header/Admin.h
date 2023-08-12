#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int fx =1;
class admin{
    public:
void addSchedule()
    {
        string BatchID,Tech,days,startDate,endDate,venue,participants,month;
        cout<<"Enter the following details: "<<endl;
        cout<<"BATCH ID: ";
        cin>>BatchID;
        cout<<"TECHNOLOGY NAME: ";
        cin>>Tech;
        cout<<"NUMBER OF DAYS: ";
        cin>>days;
        cout<<"START DATE(DD MM YYYY): ";
        cin>>startDate;
        cout<<"END DATE: ";
        cin>>endDate;
        cout<<"VENUE: ";
        cin>>venue;
        cout<<"NUMBER OF PARTICIPANTS: ";
        cin>>participants;
        cout<<"Enter month: ";
        cin>>month;
        fstream file;
        file.open("/Users/AN20449220/Desktop/CapstoneProject/csv/data.csv",std::ios::out | std::ios::app);
        file<<BatchID<<","<<Tech<<","<<days<<","<<startDate<<","<<endDate<<","<<venue<<","<<participants<<","<<month<<"\n";

}

void modifySchedule(){
    fstream data;
    data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/data.csv", ios::in);
    int count=0;
    string details,word,l;
    vector<string> datav;
    while(getline(data,l))
    {
        count++;
    }
    data.close();
    data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/data.csv", ios::in);
    
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
    string BatchID;
    cout<<"Enter the batch id you want to modify"<<endl;
    cin>>BatchID;
    
    int length = datav.size();
    int i=0;
    int flag=0;
    string Tech,days,startDate,endDate,venue,participants,month;
        cout<<"Enter 1 for Technology Modification"<<endl;
        cout<<"Enter 2 for No. of Days Modification"<<endl;
        cout<<"Enter 3 for Start Date Modification"<<endl;
        cout<<"Enter 4 for End Date Modification"<<endl;
        cout<<"Enter 5 for Venue Modification"<<endl;
        cout<<"Enter 6 for No. of Participants Modification"<<endl;
        cout<<"Enter 7 for the Month of Training Modification"<<endl;
        int choice;
        cin>>choice;
        string mod;
        while(i<length){
            if(datav[i]==BatchID){
                cout<<"Enter data";
                cin>>mod;
                datav[i+choice]=mod;
                flag =1;
            }
            i=i+8;
        }
        if(flag == 0){
            cout<<"Training Schedule not found. Please Enter the correct Batch ID"<<endl;
        }
        data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/data.csv",std::ios::out | std::ios::trunc);
    
        int x =0;
        while(x<length){
            data<<datav[x]<<","<<datav[x+1]<<","<<datav[x+2]<<","<<datav[x+3]<<","<<datav[x+4]<<","<<datav[x+5]<<","<<datav[x+6]<<","<<datav[x+7]<<"\n";
            x=x+8;
        }
        data.close();
}

void getReport(){
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
    string BatchID,Tech,days,startDate,endDate,venue,participants,month;
    cout<<"Enter Technology to get report"<<endl;
    cin>>Tech;
    cout<<"Enetr Month of training "<<endl;
    cin>>month;

    int length = datav.size();
    int i=0;
    int flag=0;
        while(i<length){
            if(datav[i+1]==Tech && datav[i+7]==month){
            flag =1;
            cout<<"BatchID: "<<datav[i]<<" Technology: "<<datav[i+1]<<" No. Of days: "<<datav[i+2]<<" Start Date: "<<datav[i+3]<<" End Date: "<<datav[i+4]<<" Venue: "<<datav[i+5]<<" Participants: "<<datav[i+6]<< " Month: "<<datav[i+7]<<" Faculty Name: "<<datav[i+8]<<" Status: "<<datav[i+9]<<endl;
            }
            i=i+10;
        }
        if(flag==0){
            cout<<"Report Geenrating Error"<<endl;
        }


}
void allocateFaculty(){
    fstream data;
    data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/data.csv", ios::in);
    int count=0;
    string details,word,l;
    vector<string> datav;
    while(getline(data,l))
    {
        count++;
    }
    data.close();
    data.open("/Users/AN20449220/Desktop/CapstoneProject/csv/data.csv", ios::in);

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
    string BatchID,Tech,days,startDate,endDate,venue,participants,month,facultyname;
    cout<<"Enter Batch ID"<<endl;
    cin>>BatchID;
    cout<<"Enter Technology "<<endl;
    cin>>Tech;
    cout<<"Enter Faculty Name to Allocate"<<endl;
    cin>>facultyname;
    vector<string> alloc;

    int length = datav.size();
    int i=0;
    int flag=0;
        while(i<length){
            if(datav[i]==BatchID && datav[i+1]==Tech){
                alloc.push_back(datav[i]);
                alloc.push_back(datav[i+1]);
                alloc.push_back(datav[i+2]);
                alloc.push_back(datav[i+3]);
                alloc.push_back(datav[i+4]);
                alloc.push_back(datav[i+5]);
                alloc.push_back(datav[i+6]);
                alloc.push_back(datav[i+7]);
                alloc.push_back(facultyname);
                alloc.push_back("YES");
                break;
            }
            i=i+8;
    }
            int j=0;
            fstream file;
            file.open("/Users/AN20449220/Desktop/CapstoneProject/csv/allocate.csv",std::ios::out | std::ios::app);
            file<<alloc[j]<<","<<alloc[j+1]<<","<<alloc[j+2]<<","<<alloc[j+3]<<","<<alloc[j+4]<<","<<alloc[j+5]<<","<<alloc[j+6]<<","<<alloc[j+7]<<","<<alloc[j+8]<<","<<alloc[j+9]<<"\n";

}
};
void adminlogin()
{
    
string userid,password,domain;
cout<<"Enter Your Name: ";
cin>>userid;
cout<<"Enter your Password: ";
cin>>password;

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
admin obj;
while(i<length)
{
    if(userid == users[i] && password == users[i+1] && users[i+3] == "admin")
    {
        flag=1;
    }
    i = i+4;
}
if(flag==1)
{
    int choice;
    cout<<"ADMIN, Login Successfull"<<endl;
    do{                                      
    cout<<"-----------------SCHEDULE MANAGEMENT-------------------"<<endl;
    cout<<"|                  Select An Option :                 |"<<endl;
    cout<<"|                1. Add new Schedule :                |"<<endl;
    cout<<"|            2. Modify existing Schedule :            |"<<endl;
    cout<<"|                 3. Generate Report                  |"<<endl;
    cout<<"|                 4. Allocate Trainer                 |"<<endl;
    cout<<"|               5. Exit the application :             |"<<endl;
    cout<<"-------------------------------------------------------"<<endl;

    cin>>choice;
    switch(choice){
        case 1:
            obj.addSchedule();
            flag=0;
            break;
        case 2:
            obj.modifySchedule();
            flag=0;
            break;

        case 3:
            obj.getReport();
            flag=0;
            break;
        case 4:
            obj.allocateFaculty();
            flag=0;
            break;       
        case 5:
            system("exit");
            break;
        default:
            cout<<"Invalid Input..!"<<endl;
            cout<<"Try Again.."<<endl;
            break;
        }
    }while(choice!=5 );
}
else
{
    fx++;
    if(fx<=3){
        cout<<"Enter Correct Name/Password"<<endl;
        cout<<endl;
        adminlogin();
    }
    else{
        cout<<endl;
        cout<<"Login Limit Reached...Exiting the Application"<<endl;

    }
}
}