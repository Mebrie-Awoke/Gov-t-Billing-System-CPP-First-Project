#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <ctime>
using namespace std;
struct name{
		char fname[20];
		char lname[20];
		char nationality[10];
		char mname[20];	
	};
struct Transaction {
    char name[100];
    double amount;
    char reason[200];
    char date[50];
};
Transaction t;
struct Feedback {
    char username[100];
    char message[500];
    char timestamp[50];
};
const int MAX_TRANSACTIONS = 1000;
const int MAX_FEEDBACK = 500;
Transaction govTransactions[MAX_TRANSACTIONS];
Transaction citizenTransactions[MAX_TRANSACTIONS];
Feedback feedbacks[MAX_FEEDBACK];
int govCount = 0;
int citizenCount = 0;
int feedbackCount = 0;
void DisplayMENU();
int CHOOSE(int n);
int GETTING();
void handleGovTransaction();
void handleCitizenTransaction();
void saveToFile();
void loadFromFile();
void acceptFeedback();
void viewFeedback();
void askQuestion();
void clearData();
void showDescription();
void showAboutUs();
void displayTransactions();
void printLine(char, int);
char* getCurrentTime();

int main(){
cout<<"**************GOVERNMENT BILLING SYSTEM************************************"<<endl;
	cout<<"DO YOU WANT TO ENTER THE SYSTEM? "<<endl;
	cout<<"1. Enter                  2.Exit"<<endl;
	int l;
	cin>>l;
if(l==2)
 
if(l!=1&&l!=2){
	cout<<"INVALID   PLEASE TRY AGAIN LATER"<<endl;
	
}
if(l==1){
  int choice;
  choice=GETTING();
    if(choice==1){ 
   
    cout << "\tGovernment-Citizen System"<<endl;
    for(;;){
    DisplayMENU();
        int choose;
        cout << "Enter your choice: ";
        cin >> choose;
       CHOOSE(choose);
       if(choose==-1)
       break;
     }
  }
}
    return 0;
}
int GETTING(){
name FULLNAME;
cout<<"FIRST Full NAME: ";
cin.ignore();
cin.getline(FULLNAME.fname,20);
cout<<"\nNATIONALITY: ";
cin.getline(FULLNAME.nationality,10);
cout<<"\n1. Submit                                2. Edit"<<endl;
int choice;
cout<<"\nEnter your choice ";
cin>>choice;
if(choice==2){ for(;;){
	cout<<"FIRST Full NAME: ";
    cin>>FULLNAME.fname;
    cout<<"\nNATIONALITY: ";
    cin>>FULLNAME.nationality;
    cout<<"\n1. Submit            2. Edit "<<endl;
    cin>>choice;
    if(choice!=2&&choice!=1){
	 cout<<"invalid creadential please try again later!"<<endl;
      break;}
      if(choice==1)
      break;

      
      }
   }  
return choice;	
}

void DisplayMENU(){
	cout<<endl;
	cout<<"       MAIN  MENU        "<<endl;
    printLine('=', 50);
    cout << "1. Record transaction to Government"<<endl;
    cout << "2. Record transaction to Citizens"<<endl;
    cout << "3. Save and Exit"<<endl;
    cout << "4. Load Data"<<endl;
    cout << "5. Accept Feedback"<<endl;
    cout << "6. Ask Personal Questions"<<endl;
    cout << "7. Troubled Transactions"<<endl;
    cout << "8. Description"<<endl;
    cout << "9. About Us"<<endl;
    cout << "10. View Transactions and feedbacks"<<endl;
    printLine('-', 50);
}
int CHOOSE(int n){
	        switch (n) {
            case 1:
                handleGovTransaction();
                break;
            case 2:
                handleCitizenTransaction();
                break;
            case 3:
                saveToFile();
                cout << "Data saved and exiting the system.\n";
                exit(0);
            case 4:
                loadFromFile();
                break;
            case 5:
                acceptFeedback();
                break;

            case 6:
                askQuestion();
                break;
            case 7:
                clearData();
                break;
            case 8:
                showDescription();
                break;
            case 9:
                showAboutUs();
                break;
            case 10:
                displayTransactions();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    return n;
}
void handleGovTransaction() {
    if (govCount >= MAX_TRANSACTIONS) {
        cout << "Maximum government transactions reached.\n";
        return;
    }
    if(govCount==0){
    	cout<<"Well come to Government transaction entry"<<endl;
	}
    
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(t.name, 100);
    cout << "Enter amount: ";
    cin >> t.amount;
    cin.ignore();
    cout << "Enter reason: ";
    cin.getline(t.reason, 200);
    strcpy(t.date, getCurrentTime());
    govTransactions[govCount++] = t;
     string k;
    cout<<"do you want to save it(yes/no)"<<endl;
    getline(cin,k);
    if(k=="yes"){
    	 cout << "Transaction recorded successfully.\n";
	}
	else{
	govCount = govCount - 1;
    citizenCount =citizenCount - 1;
    feedbackCount = feedbackCount - 1;
    cout<<"sorry you can not save your transaction to the file"<<endl;
	}
}

void handleCitizenTransaction() {
    if (citizenCount >= MAX_TRANSACTIONS) {
        cout << "Maximum citizen transactions reached.\n";
        return;
    }
  if(govCount==0){
    	cout<<"Well come to citzen transaction entry"<<endl;
	}
    
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(t.name, 100);
    cout << "Enter amount: ";
    cin >> t.amount;
    cin.ignore();
    cout << "Enter reason: ";
    cin.getline(t.reason, 200);
    strcpy(t.date, getCurrentTime());
    citizenTransactions[citizenCount++] = t;
     string k;
    cout<<"do you want to save it(yes/no)"<<endl;
    getline(cin,k);
    if(k=="yes"){
    	 cout << "Transaction recorded successfully.\n";
	}
	else{
	govCount = govCount - 1;
    citizenCount =citizenCount - 1;
    feedbackCount = feedbackCount - 1;
    cout<<"sorry you can not save your transaction to the file"<<endl;
	}
   
}

void saveToFile() {
	
    ofstream file("data.txt" , ios::app);
    file<<"######################################################################"<<endl;
    file<<endl;
    file<<"     "<< getCurrentTime()<<endl;
    file<<"######################################################################"<<endl;
    if(govCount>0){
    file<<"******************Gov't Transaction*************** "<<endl;
    file <<"There are "<<govCount<<" citzens transaction" << endl;
}
    for (int i = 0; i < govCount; i++) {
    	file<<i+1<<". ";
        file <<"Name: "<< govTransactions[i].name <<", ";
        file <<"Amount: "<< govTransactions[i].amount << ", ";
        file << "Reason of transaction: "<<govTransactions[i].reason << ", ";
        file <<"Date of transaction: "<< govTransactions[i].date << endl;
    
    }

  if(citizenCount>0){
    file<<"********************Citzen Transaction****************** "<<endl;
    file <<"There are "<<citizenCount<<" citzens transaction" << endl;
   }
    for (int i = 0; i < citizenCount; i++) {
       file<<i+1<<". ";
		file <<" Name: "<<citizenTransactions[i].name << ", ";
        file << "Amount: "<<citizenTransactions[i].amount << ", ";
        file << "Reason of transaction: "<<citizenTransactions[i].reason << ", ";
        file << "Date of transaction: "<<citizenTransactions[i].date << endl;
    }
    
  if(feedbackCount>0){
    file<<"****************Given feedbacks from citzens*****************"<<endl;
    file <<"There are " <<feedbackCount<<" number of feedbacks given" << endl;
   }
    for (int i = 0; i < feedbackCount; i++) {
    	file<<i+1<<". ";
        file << "User name: "<<feedbacks[i].username << endl;
        file << "Given feedback: "<<feedbacks[i].message << endl;
        file << "At: "<<feedbacks[i].timestamp << endl;
    }
     
    file<<"######################################################################"<<endl;
    file.close();
    
}

void loadFromFile() {
    ifstream file("data.txt",ios::app);
    if (!file) {
        cout << "No data file found.\n";
        return;
    }
    file >> govCount;
    file.ignore();
    for (int i = 0; i < govCount; i++) {
        file.getline(govTransactions[i].name, 100);
        file >> govTransactions[i].amount;
        file.ignore();
        file.getline(govTransactions[i].reason, 200);
        file.getline(govTransactions[i].date, 50);
    }

    file >> citizenCount;
    file.ignore();
    for (int i = 0; i < citizenCount; i++) {
        file.getline(citizenTransactions[i].name, 100);
        file >> citizenTransactions[i].amount;
        file.ignore();
        file.getline(citizenTransactions[i].reason, 200);
        file.getline(citizenTransactions[i].date, 50);
    }

    file >> feedbackCount;
    file.ignore();
    for (int i = 0; i < feedbackCount; i++) {
        file.getline(feedbacks[i].username, 100);
        file.getline(feedbacks[i].message, 500);
        file.getline(feedbacks[i].timestamp, 50);
    }
    file.close();
    cout << "Data loaded successfully."<<endl;
}

void acceptFeedback() {
    if (feedbackCount >= MAX_FEEDBACK) {
        cout << "Maximum feedback limit reached."<<endl;
        return;
    }
    Feedback f;
    cout << "Enter username: ";
    cin.ignore();
    cin.getline(f.username, 100);
    cout << "Enter feedback: ";
    cin.getline(f.message, 500);
    strcpy(f.timestamp, getCurrentTime());
    feedbacks[feedbackCount++] = f;
    
         string k;
    cout<<"do you want to save it(yes/no)"<<endl;
    getline(cin,k);
    if(k=="yes"){
      cout << "Feedback recorded. Thank you!"<<endl;
	}
	else{
	govCount = govCount - 1;
    citizenCount =citizenCount - 1;
    feedbackCount = feedbackCount - 1;
    cout<<"sorry you can not save your feedback to the file"<<endl;
	}
  
}


void askQuestion() {
	string Question;
	int choice;
	string username;
	string refer;
	string Answers;
    cout << "Wellcome To The question And Answer Entry"<<endl;
    cout<<"What do you want?"<<endl;
    cout<<"1. To ask the question"<<endl;
    cout<<"2. To view the questions and answers"<<endl;
    cout<<"3. try to answer the questions"<<endl;
    cin>>choice;
    if(choice==1){
    cout<<"You can ask three question at a time"<<endl;
    cin.ignore();
    getline(cin,Question);
    ofstream offile("QUESTION.txt",ios::app);
    offile<<Question<<" are asked at "<<getCurrentTime()<<endl;
    offile.close();
    }
    
   if(choice==2){
   	ifstream infile("QUESTION.txt");
   	string data;
   	 while(getline(infile,data))
   	   cout<<data<<endl;
   }

  
   if(choice==3){
   	cout<<"Enter user name: ";
   	 getline(cin,username);
   	 cout<<"Which questions do you want to answer(date and q#)?"<<endl;
   	 getline(cin,refer);
   	 cout<<"you can start ansering it"<<endl;
   	 getline(cin,Answers);
   	ofstream offile("QUESTION.txt",ios::app);
   	offile<<"The questions "<<refer<<" answered "<<Answers <<" by "<<username<<" At "<<getCurrentTime()<<endl;
   	 offile.close();
 }	
}

void clearData() {
	int code;
	string name;
	string date;
	string reason;
	cout<<"Enter the password: ";
	cin>>code;
	if(code==1234){
    cout<<"Enter the name of the person: "<<endl;
    cin>>name;
    cin.ignore();
    cout<<"Enter the day of transaction happened in this format (Thu Jan 02 19:55:50 2025)"<<endl;
    getline(cin,date);
    	cout<<"What is the reason of the problem?"<<endl;
    	k:getline(cin,reason);
    	if(reason=="")
    	 goto k;
    ofstream file("spam.txt",ios::app);
    file<<endl;
    file<<"Name of the person: "<<name<<"   ";
    file<<"Date of transaction"<<date<<"   ";
    file<<"Date of spammed: "<<getCurrentTime()<<endl;
    file<<"Reason: "<<reason;
    file.close();
    cout << "the data saved in spammed "<<endl;
   }
  else
   cout<<"sorry you can't spam the transaction"<<endl;
}

void showDescription() {
	cout<<"******************Well come to the description box*********************"<<endl;
	
    cout <<"This system manages transactions between citizens and the government."<<endl;
    
    cout<<"This system generally doing transaction between government and citzen."<<endl;
    
    cout<<"You must use the sysytem by using the following guidelines: "<<endl;
    
    cout<<"1. Any one can transact from citzen to government, first choose the entry and by following the steps."<<endl;
    
    cout<<"2. Any one can't transact from government to citzens exept the admins or workers of the system."<<endl;
    
    cout<<"3. Any person can give the feedback at any time."<<endl;
    
    cout<<"4. citzens can ask personal questions that will see by all users and someone can answer it"<<endl;
    
    cout<<"5. Don't forget if you enter something to the system you must do it with the respective data types,\n"
	        << "this may cause for infinite iteration."<<endl;
	        
    cout<<"6. Don't try to delete the saved datas this may take risk for you exept admins "<<endl;
    
    cout<<"7. you can see the transactions that recorded, but it maybe have very vast\n transaction records"
            <<". In this time you can find the record that you want by date of transaction "<<endl;
            
    cout<<"8. If somebody saved transaction, that encounter some errors, sequentially he/she must tell for work man. \n"
            <<" The work man save the problem on his file  "<<endl;
            
    cout<<"9. NOTICE: The saved transactions, that encounter problems are see for only work mans"<<endl;
	cout<<""<<endl;
    cout<<""<<endl;
}

void showAboutUs() {
    cout << "***********************Well come to know about the owners of the sysytem********"<<endl;
    
    cout<<"I am from Addis Ababa University Information System Students"<<endl;
    
    
    cout<<"The topic is selected by mebrie and also planned by mebrie"<<endl;
    
    cout<<"The discription box is prepared by mebrie"<<endl;
    
    cout<<"The whole logo is prepared by Mebrie Awoke"<<endl;
    
    cout<<"Other parts are prepared mebrie awoke"<<endl;
    
    cout<<"For your personal feedback about the sysytem use: "<<endl;
        cout<<"  Telegram: @ze_meryma_21 "<<endl;
        cout<<"  Email adress: mebrieawoke941@gmail.com"<<endl;
        cout<<"  Phone call:  +251 922 545 447"<<endl;
}

void displayTransactions() {
	ifstream infile("data.txt");
	string data;
	while(getline(infile,data)){
		cout<<data<<endl;	
	}

}

void printLine(char ch, int count) {
    for (int i = 0; i < count; i++) 
	   cout << ch;
    cout << endl;
}

char* getCurrentTime() {
    time_t now = time(0);
    return ctime(&now);
}

