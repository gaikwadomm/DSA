#include<iostream>
#include<vector>
using namespace std;

class a{
    // b p p p n n n n c p p p p p p p d d d d d d d d
    char b;
    int n; //4 bytes
    char c;  //char will also get 4 bytes as by the concept of padding in C++
    // what is padding? 
    // padding is the process of adding extra bytes to align data in memory
    // padding is done to make the data structure more efficient in terms of memory access 
    double d;   
};

class Student{
    // public:
    //     string name;
    //     int age, roll_number;
    //     string grade;
    string name;
    int age, roll_number;
    string grade;
    public:
        void setName(string s){
            if(s.size()==0){ 
                cout<<"Invalid Name";
                return;
            }
            name = s;
        }
        void setAge(int n){
            if(age<0 || age>100){
                cout<<"Invalid User";
                return; 
            }
            age = n;
        };
        void setRoll_no(int r){
            roll_number = r;
        }
        void setGrade(string s){
            grade = s;
        }
        void getName(){
            cout<<name<<endl;
        }
};

int main(){
    // Student s1;
    // s1.setName("om gaikwad");
    // s1.setAge(19);
    // s1.setGrade("A");
    // s1.setRoll_no(14);
    // s1.getName();

    a obj;
    cout<<sizeof(obj);
}
