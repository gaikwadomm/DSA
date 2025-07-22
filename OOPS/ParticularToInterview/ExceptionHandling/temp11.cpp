#include<iostream>
using namespace std;



int main(){
    try {
        int a = 10, b = 0;
        if (b == 0) {
            throw "Division by zero error";
        }
        cout << "Result: " << a / b << endl;
    } catch (const char* msg) {
        cerr << "Caught an exception: " << msg << endl;
    }

    return 0;
}