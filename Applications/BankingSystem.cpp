#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;

#define MIN_BALANCE 500

class InSufficientFunds{};

class Account{
 private:
     long AccountNumber;
     string FirstName;
     string LastName;
     float balance;
     static long NextAccountNumber;
 public:
    Account(){}
    Account(string fname, string lname, float balance);
    long getAccountNumber(){
    return AccountNumber;
    }
    string getFirstName(){
     return FirstName;
    }
    string getLastName(){
     return  LastName;
    }
    float getBalance(){
     return balance;
    }

    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    friend ofstream & operator << (ofstream &ofs, Account &acc);
    friend ifstream & operator >> (ifstream &ifs, Account &acc);
    friend ostream & operator << (ostream &os, Account &acc);
};
long Account::NextAccountNumber=0;

class Bank{
 private:
     map<long, Account> accounts;
 public:
    Bank();
    Account OpenAccount(string fname, string lname, float balance);
    Account BalanceInquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccount();
    ~Bank();
};

int main(){
 Account acc;
 Bank b;
 int choice;
 string fname;
 string lname;
 long accountNumber;
 float amount;
 float balance;
 cout<< "### Welcome To Banking System ###";
 do{
 cout<< "\n\tPlease select an option";
 cout<< "\n\t1 Open an Account";
 cout<< "\n\t2 Balance Inquiry";
 cout<< "\n\t3 Deposit";
 cout<< "\n\t4 Withdraw";
 cout<< "\n\t5 Show All Accounts";
 cout<< "\n\t6 Close Account";
 cout<< "\n\t7 Quite";
 cout<< "\nPlease enter your choice: ";
 cin>>choice;
 switch(choice){
  case 1:
      cout<< "Please Enter First Name: ";
      cin>>fname;
      cout<< "Please Enter Last Name: ";
      cin>>lname;
      cout<< "Please Enter Initial Balance: ";
      cin>> balance;
      acc = b.OpenAccount(fname, lname, balance);
      cout<< "\n*Congratulation!! Your Account is Created*"<<endl;
      cout<<acc;
      break;
  case 2:
      cout<< "Please Enter Account Number: ";
      cin>>accountNumber;
      acc = b.BalanceInquiry(accountNumber);
      cout<< "\nYou Bank Details" <<endl;
      cout<<acc;
      break;
  case 3:
      cout<< "Please Enter Account Number: ";
      cin>>accountNumber;
      cout<< "Please Enter Amount: ";
      cin>>amount;
      acc = b.Deposit(accountNumber,amount);
      cout<< "\nAmount is Deposited: "<<endl;
      cout<< acc;
      break;
  case 4:
      cout<< "Please Enter Account Number: ";
      cin>> accountNumber;
      cout<< "Please Enter Amount: ";
      cin>>amount;
      acc = b.Withdraw(accountNumber, amount);
      cout<< "\nAmount is Withdrawn: ";
      cout<<acc;
      break;
  case 5:
      b.ShowAllAccount();
      break;
  case 6:
      cout<< "Please Enter Account Number: ";
      cin>>accountNumber;
      b.CloseAccount(accountNumber);
      cout<<acc;
      break;
  case 7:
      cout<< endl<< "$$$$$$$/ Thank You! for visiting our Banking System. /$$$$$$$"<<endl;
      exit(0);
      break;
  default:
    cout<< "\nPlease enter correct choice"<<endl;
    exit(0);
  }
 }while(choice=7);
 return 0;
}
Account::Account(string fname, string lname, float balance){
 NextAccountNumber++;
 AccountNumber= NextAccountNumber;
 FirstName = fname;
 LastName = lname;
 this->balance = balance;
}
void Account::Deposit(float amount){
 balance += amount;
}
void Account::Withdraw(float amount){
 if(balance-amount<MIN_BALANCE)
     throw InSufficientFunds();
 balance -=amount;
}
void Account::setLastAccountNumber(long accountNumber){
 NextAccountNumber = accountNumber;
}
long Account::getLastAccountNumber(){
 return NextAccountNumber;
}
ofstream & operator << (ofstream &ofs, Account &acc){
 ofs<< acc.AccountNumber<<endl;
 ofs<< acc.FirstName<<endl;
 ofs<< acc.LastName<<endl;
 ofs<< acc.balance<<endl;
 return ofs;
}
ifstream & operator >> (ifstream &ifs, Account &acc){
 ifs>> acc.AccountNumber;
 ifs>> acc.FirstName;
 ifs>> acc.LastName;
 ifs>> acc.balance;
 return ifs;
}
ostream & operator << (ostream &os, Account &acc){
 os<< "Account Number: "<< acc.getAccountNumber()<<endl;
 os<< "First Name: "<<acc.getFirstName()<<endl;
 os<< "Last Name: "<<acc.getLastName()<<endl;
 os<< "Balance: "<< acc.getBalance()<<endl;
 return os;
}

Bank::Bank(){
 Account account;
 ifstream infile;
 infile.open("Bank.data");
 if(!infile){
    //cout<< "File is not opening, Since file is not found";
    return;
 }
 while(!infile.eof()){
    infile>>account;
    accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
}
Account::setLastAccountNumber(account.getAccountNumber());
  infile.close();
}
Account Bank::OpenAccount(string fname, string lname, float balance){
 ofstream outfile;
 Account account(fname, lname, balance);
 accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
 outfile.open("Bank.data",ios::trunc);
 map<long, Account>::iterator itr;
 for(itr=accounts.begin(); itr!= accounts.end(); itr++){
    outfile<<itr->second;
 }
 outfile.close();
 return account;
}
Account Bank::BalanceInquiry(long accountNumber){
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 return itr->second;
}
Account Bank::Deposit(long accountNumber, float amount){
 map<long, Account>::iterator itr=accounts.find(accountNumber);
 itr->second.Deposit(amount);
 return itr->second;
}
Account Bank::Withdraw(long accountNumber, float amount){
 map<long, Account>::iterator itr=accounts.find(accountNumber);
 itr->second.Withdraw(amount);
 return itr->second;
}
void Bank::CloseAccount(long accountNumber){
 map<long, Account>::iterator itr=accounts.find(accountNumber);
 cout<< "Account Deleted\n"<<itr->second;
 accounts.erase(accountNumber);
}
void Bank::ShowAllAccount(){
 map<long, Account>::iterator itr;
 for(itr=accounts.begin(); itr!=accounts.end(); itr++){
    cout<< "Account "<< itr->first<<endl<<itr->second<<endl;
 }
}
Bank::~Bank(){
 ofstream outfile;
 outfile.open("Bank.data",ios::trunc);
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++){
    cout<< itr->second;
 }
 outfile.close();
}
