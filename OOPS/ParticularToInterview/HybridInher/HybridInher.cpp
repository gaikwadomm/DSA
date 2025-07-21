#include <iostream>
using namespace std;

//In hybrid inheritance, its a combination of multiple inheritance and hierarchical inheritance.
//Refer to the image for better understanding.

// Parent class 1
class Male {
public:
    void showMale() {
        cout << "I am Male" << endl;
    }
};

// Parent class 2
class Student {
public:
    void showStudent() {
        cout << "I am a Student" << endl;
    }
};

// Boy inherits from Male and Student
class Boy : public Male, public Student {
public:
    void showBoy() {
        cout << "I am a Boy (Male Student)" << endl;
    }
};

// Female parent class
class Female {
public:
    void showFemale() {
        cout << "I am Female" << endl;
    }
};

// Girl inherits from Female and Student
class Girl : public Female, public Student {
public:
    void showGirl() {
        cout << "I am a Girl (Female Student)" << endl;
    }
};

int main() {
    Boy boyObj;
    Girl girlObj;

    cout << "Boy object:" << endl;
    boyObj.showMale();
    boyObj.showStudent();
    boyObj.showBoy();

    cout << "\nGirl object:" << endl;
    girlObj.showFemale();
    girlObj.showStudent();
    girlObj.showGirl();

    return 0;
}