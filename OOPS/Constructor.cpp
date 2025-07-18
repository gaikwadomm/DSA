#include<iostream>
#include<vector>
using namespace std;

class myConstructor{
    public:
    string name;
    int marks;
    int RollNo;
    //Default constructor
    myConstructor(){
        name = "om dhavle";
        marks = 95;
    }

    //parametrized constructor
    myConstructor(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    //Constructor Overloading
    myConstructor(int RollNo){
        this->RollNo = RollNo;
    }

    //Inline Constructor
    inline myConstructor(string a, int b, int c): name(a), marks(b), RollNo(14){

    }

    //copy constructor
    myConstructor(myConstructor& a){
        this->name = a.name;
        this->marks = a.marks;
    }
};

int main(){
    // myConstructor user1("om gaikwad", 87);
    // myConstructor user2("harsh", 97, 21);
    // cout<<user1.name<<endl;
    // cout<<user2.name;

    myConstructor user1("om gaikwad", 87, 14);
    cout<<user1.name<<endl;
    myConstructor user2(user1);
    cout<<user2.name;
}
