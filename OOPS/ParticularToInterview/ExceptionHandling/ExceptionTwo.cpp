#include<iostream>

using namespace std;

int main(){
    try{
        int n;
        cout << "Enter a number: ";
        cin >> n;
        int *p = new int[n]; // Trying to allocate a huge amount of memory
        cout << "Memory allocated successfully." << endl;
        delete[] p; // Freeing the allocated memory
    } catch(const exception& e){
        cout<<"Memory allocation failed. Not enough memory available." <<e.what()<< endl;
    }
}