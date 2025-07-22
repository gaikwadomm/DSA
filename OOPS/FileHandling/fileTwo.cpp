#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin;

    // Open the file for reading
    fin.open("zoom.txt");
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1; // Exit if the file cannot be opened
    }
    char c;
    // Read characters from the file until the end of the file is reached
    //but the below code reads character by character
    //the space is not considered and not printed
    // fin>>c;
    // while(!fin.eof()){
    //     cout<<c;
    //     fin>>c;
    // }

    c = fin.get();
    while(!fin.eof()){
        cout << c;
        c = fin.get(); // Read the next character
    }
    // Close the file
    fin.close();
}