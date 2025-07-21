#include <iostream>
using namespace std;

//The hierarchical inheritance example in C++ demonstrates how a base class can be inherited by multiple derived classes.
//Single parent class with multiple child classes
// Base class
class Animal {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    cout << "Dog:" << endl;
    d.eat();
    d.bark();

    cout << "\nCat:" << endl;
    c.eat();
    c.meow();

    return 0;
}