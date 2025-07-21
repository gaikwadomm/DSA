#include <iostream>
using namespace std;

//Mulitple parent classes example
// demonstrating multiple inheritance in C++
// Base class 1
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

// Base class 2
class Bird {
public:
    void fly() {
        cout << "Bird is flying." << endl;
    }
};

// Derived class inheriting from both Animal and Bird
class Bat : public Animal, public Bird {
public:
    void sleep() {
        cout << "Bat is sleeping." << endl;
    }
};

int main() {
    Bat b;
    b.eat();   // From Animal
    b.fly();   // From Bird
    b.sleep(); // Own method
    return 0;
}