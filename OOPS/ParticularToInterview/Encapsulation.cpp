#include<iostream>
using namespace std;

//What is encapsulation?
//Encapsulation is a fundamental concept in object-oriented programming (OOP) that restricts direct access to an object's data and methods.
class LearnEncapsulation {
    private:
        int amount;
        int age;

    public:
        // Constructor to initialize the values
        //Now let see the real use of encapsulation
        //Now because of encapsulation we can access the private members
        //and also check if they are valid or not to avoid any kind of wrong data to be stored
        LearnEncapsulation(int amount, int age){
            if( amount>= 0 && age > 15 && age < 100) {
                this->amount = amount;
                this->age = age;
            }
            else {
                cout << "Invalid values provided!" << endl;
                amount = 0; // Default value
                age = 0;    // Default value
            }
        }

        // Function to display the values
        void display() {
            if(amount < 0 || age < 0) {
                cout << "Invalid data!" << endl;
            } else {
                cout << "Amount: " << amount << ", Age: " << age << endl;
            }
        }
};

int main(){
    LearnEncapsulation obj1(100, 20); // Valid values
    obj1.display();

    LearnEncapsulation obj2(-50, 10); // Invalid values
    obj2.display();

    LearnEncapsulation obj3(200, 18); // Valid values
    obj3.display();

    return 0;
}
