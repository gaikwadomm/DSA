#include <iostream>
using namespace std;

class Human {
    public:
    string name;

    void show() {
        cout << "My naame is " << name << endl;
    }
};

// Note the use of virtual inheritance to solve the multipath problem
class Youtuber : public virtual Human {
    public:
    int subscribers;

    void displayYoutube(){
        cout << "I have " << subscribers << " subscribers on YouTube." << endl;
    }
};

class Engineer : public virtual Human {
    public:
    string speciallization;
    void displayEngineering() {
        cout << "I am an engineer with specialization in " << speciallization << "." << endl;
    }
};

class CodeTeacher : public Youtuber, public Engineer {
    public:
    int salary;

    CodeTeacher(string name, string speciallization, int subscribers, int salary){
        this->name = name;
        this->speciallization = speciallization;
        this->subscribers = subscribers;
        this->salary = salary;
    }
};

int main() {
    //If virtual inheritance is not used, the following line will cause ambiguity
    //This will give an error bcoz of name ambiguity
    CodeTeacher ct("John Doe", "Software Engineering", 100000, 50000);
    ct.show();
    ct.displayYoutube();
    ct.displayEngineering();
    cout << "My salary is " << ct.salary << " dollars." << endl;
    return 0;
}