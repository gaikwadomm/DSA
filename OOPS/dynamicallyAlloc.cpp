#include<iostream>
#include<vector>
using namespace std;

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
            if(n<0 || n>100){
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

    //This will store the object in heap memory 
    // and we can access it using pointer
    // This is called dynamic memory allocation
    // We can use new keyword to allocate memory dynamically
    // and delete keyword to deallocate memory
    Student *s1 = new Student;
    (*s1).setName("om gaikwad");
    //or
    (*s1).setAge(19);
    (*s1).setGrade("A");
    (*s1).setRoll_no(14);
    (*s1).getName();
    
}
