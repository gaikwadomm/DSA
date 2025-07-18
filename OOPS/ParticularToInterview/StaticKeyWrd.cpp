#include<iostream>
using namespace std;

class customer{
    string name;
    int acc_no, balance;
public:
    static int total_customers;
    static int total_balance;
    customer(string a, int b, int c){
        name = a;
        acc_no = b;
        balance = c;
        total_customers++;
        total_balance += c;
    }

    // Static method to access static members
    // This method can be called without an instance of the class
    // It is used to access static members of the class
    //They cant access non-static members directly
    static void accessStatic() {
        cout<<"Total customers: "<<total_customers<<endl;
        cout<<"Total balance: "<<total_balance<<endl;
        // Note: Cannot access non-static members directly here
        // cout << "Name: " << name; // This would cause an error
    }

    void display(){
        cout<<"Total Customers: "<<total_customers<<endl;
        cout<<"Total Balance: "<<total_balance<<endl;
    }
};
int customer::total_customers = 0;
int customer::total_balance = 0;

int main(){
    customer c1("Alice", 1001, 5000);
    customer c2("Bob", 1002, 3000);
    customer c3("Charlie", 1003, 7000);
    c1.display();
    c2.display();
    c3.display();
    customer::total_customers = 7; // Directly accessing static member
     customer::accessStatic(); // Accessing static method using class name
    
    c3.display();
}
