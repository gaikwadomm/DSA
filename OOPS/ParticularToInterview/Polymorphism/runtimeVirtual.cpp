#include<iostream>
#include<vector>
using namespace std;

class Animal{
    public:
    //virtual use to say compiler do this in runtime
    //when we call this function, it will check the object type at runtime
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }

    //pure virtual function
    // virtual void sound() = 0; // Uncommenting this line will make Animal an abstract class
};

class Dog : public Animal{
    public:
    void sound(){
        cout << "Dog barks" << endl;
    }
    // Uncommenting the following method will cause a compilation error
    // because it does not override the base class method

    // void roti(){
    //     cout << "Dog eats roti" << endl;
    // }
};
class Cat : public Animal{
    public:
    void sound(){
        cout << "Cat Meow" << endl;
    }
};

int main(){   
    // Dog d;
    // d.sound();
                   
    // Animal* p;
    // p = new Dog();
    // p->sound(); // Calls Dog's sound method due to runtime polymorphism
    // delete p; // Clean up memory

    Animal *p;
    vector<Animal*> animals;
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for(int i = 0; i < animals.size(); i++){
        animals[i]->sound(); // Calls the appropriate sound method based on the actual object type
    }
    // // Clean up memory
    // for(int i = 0; i < animals.size(); i++){
    //     delete animals[i];
    // }
}