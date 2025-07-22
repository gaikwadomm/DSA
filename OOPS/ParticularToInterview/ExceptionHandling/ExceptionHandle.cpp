#include<iostream>
#include<string>
using namespace std;

class InvalidAmountError : public runtime_error {
    public:
    InvalidAmountError(const string& message) : runtime_error(message) {}
};

class InsufficientBalanceError : public runtime_error {
    public:
    InsufficientBalanceError(const string& message) : runtime_error(message) {}
};

class Customer{
    string name;
    int balance, account_number;

    public:
    Customer(string name, int balance, int account_number){
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }
    void deposit(int amount){
        if(amount<0){
            throw InvalidAmountError("amount should be greater than 0");
        }
        balance+=amount;
        cout<<amount<<" deposited\n";

    }
    void withdraw(int amount){
        if(amount>0 && amount<=balance){
            balance-=amount;
            cout<<amount<<" is debited\n";
        } else if(amount<0){
            throw InvalidAmountError("amount should be greater than 0");
        } else{
            throw InsufficientBalanceError("Your balance is low");
        }
    }
};

int main(){
    Customer c1("om", 5000, 10);
    try
    {
        c1.deposit(100);
        c1.withdraw(6000);
        c1.deposit(100);
    }
    catch(const InvalidAmountError& e)
    {
        cout<<"Exception OOccurred : "<<e.what()<<endl;
    }
    catch(const InsufficientBalanceError& e){
        cout<<"Memory allocation failed: "<<e.what()<<endl;

    }
    catch(...){
        cout<<"An unknown error occurred."<<endl;

    }
    
}