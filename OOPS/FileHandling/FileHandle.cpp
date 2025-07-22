#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //File ko open karna 
    // ofstream fout;
    // //If file not preset, it will create a new file
    // //If file is present, it will overwrite the existing file
    // fout.open("zoom.cpp");

    // fout<<"Hello India\n";
    // // fout<<"#include<iostream>\n using namespace std;\n\n int main(){\n cout<<\"Hello World\";\n return 0;}";


    // //File ko close karna
    // fout.close();

    // vector<int> arr(5);
    // cout<<"Enter 5 elements in the array: ";
    // for(int i = 0; i < 5; i++) {
    //     cin >> arr[i];
    // }

    // // File ko open karna (append mode)
    // ofstream fout;
    // fout.open("newFile.txt", ios::app); // ios::app se purane data ke sath naya data add hoga

    // // File me likhna
    // for(int i = 0; i < 5; i++) {
    //     fout << arr[i] << " ";
    // }

    // fout<<"\nSorted Data: ";

    // sort(arr.begin(), arr.end());
    // for(int i = 0; i < 5; i++) {
    //     fout << arr[i] << " ";
    // }
    // fout.close();


    // ofstream fout;
    // fout.open("z1.txt");
    // fout<<"Hello India\n";
    // fout<<"Hello Om\n";
    // fout<<"Hello World\n";
    // fout.close();

    ifstream fin;
    fin.open("z1.txt");
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1; // Exit if the file cannot be opened
    }
    string line;
    while(getline(fin, line)){
        cout << line << endl; // Print each line read from the file
    }
    fin.close();
    return 0; // Return 0 to indicate successful execution
}