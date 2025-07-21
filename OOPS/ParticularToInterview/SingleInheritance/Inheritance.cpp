#include<iostream>
using namespace std;

//What is Private, Public, Protected in C++?
// Private members are accessible only within the class itself.
// Public members are accessible withing the class, from derived classes, and from outside the class.
// Protected members are accessible within the class, from derived classes, but not from outside the class.

class Human{
    string name;
    int age;
    protected:
    // Protected members can be accessed in derived classes
        string address;
    public:
        Human(string name, int age, string address = ""){
            this->name = name;
            this->age = age;
            if(address.size()!=0){
                 this->address = address;
                } // Initialize address if provided
            else{
                 this->address = "Not provided"; 
                }// Default value if not provided
        }
        void display(){
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

// Inheritance from Human class
//public is access modifier
//there are others as well like private, protected
class Student : public Human {
    string university;

public:
    Student(string name, int age, string university, string address = "")
        : Human(name, age, address) // Correct way to call base class constructor
    {
        this->university = university;
    }
    void display(){
        Human::display(); // Call the base class display method
        cout << "University: " << university << endl;
        cout << "Address: " << address << endl; // Accessing protected member
        if(address == "Not provided") {
            this->address = "Mum"; // Default address if not provided
            cout << "Address is not provided. Setting default to "<<address << endl;
        }
    }
};

int main(){
    Student s("John Doe", 20, "XYZ University");
    s.display(); // Display student information
    return 0;
}