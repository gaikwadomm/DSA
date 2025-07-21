#include<iostream>
using namespace std;

class Person{

    string skinColor;
    string religion;
    protected:
        string name;
        string address;
        string gender;
        int age;
    public:
        Person(string name, string address, string gender, int age){
            this->name = name;
            this->address = address;
            this->gender = gender;
            this->age = age;
            cout << "Person name: " << name << endl;
        };
        void display() {
            cout << "Person class" << endl;
        };
    };

class Employee : public Person{

    protected:
        string department;
        string designation;
        static int empId;
    public:
        Employee(string name, string address, string gender, int age, string department, string designation)
            : Person(name, address, gender, age){
            this->empId++;
            this->department = department;
            this->designation = designation;
            cout << "Employee ID: " << empId << " employee is "<<name<<endl;
            }
        void display() {
            cout << "Employee class" << endl;
        }
};
int Employee::empId = 0; // Initialize static member variable

class Manager : public Employee{
    int managerId;
    public:
    Manager(string name = "Default Name", string address = "Default Address", string gender = "Unknown", int age = 0, string department = "Default Department", string designation = "Default Designation")
        : Employee(name, address, gender, age, department, designation) {
        this->managerId = empId;
        cout << "Manager ID: " << managerId << " manager is " << name << endl;
    }
    void display() {
        cout << "Manager class" << endl;
    }

};
int main() {
    Person P("Jordan Lee", "789 Pine", "male", 25);
    Employee E("Nick Smith", "456 Elm", "male", 28, "HR", "Recruiter");
    Manager M("John Doe", "123 Main", "male", 30, "IT", "Software Engineer");
    // P.display();
    // E.display();
    return 0;
}   