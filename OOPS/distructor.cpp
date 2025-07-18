#include<iostream>
using namespace std;

class Customer{
    string name;
    int *data;

    public:
    Customer(string name){
        this->name = name;
        data = new int;
        *data = 10;
        cout<<"Constructor is called "<<name<<endl;
    }

    //releases the memory which get dynamically
    ~Customer(){
        delete data;
        cout<<"Distructor is called "<<name<<endl;
    }
};


int main(){
    Customer a("1"), b("2"), c("3");
}