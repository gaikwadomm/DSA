#include<iostream>
#include<map>
#include<vector>
using namespace std;

//It store data in key value pair format
//Keys are unique, and values can be duplicated
//Implemented using AVL or Red-Black Tree
//Time Complexity: O(log n) for insertion, deletion, and search operations

int main()
{
    // Create a map to store integer keys and string values
    map<int, string> myMap;

    // Insert key-value pairs into the map
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Cherry";

    // Access and print values using their keys
    cout << "Key 1: " << myMap[1] << endl;
    cout << "Key 2: " << myMap[2] << endl;
    cout << "Key 3: " << myMap[3] << endl;

    // Iterate through the map and print all key-value pairs
    cout << "All key-value pairs in the map:" << endl;
    for (const auto& pair : myMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    map<int, int> newMap;
    newMap.insert(make_pair(20,30));
    newMap.insert(make_pair(30,50));
    newMap.insert(make_pair(40,70));
    newMap.insert(make_pair(30,90));
    newMap.insert(make_pair(50,80));

    cout<<"All key val pairs in the map:"<<endl;
    for(auto it = newMap.begin();it!=newMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    map<int, vector<int>> arrMap;
    vector<int> n1={1,2,3}, n2={4,5,6}, n3={7,8,9};
    arrMap.insert(make_pair(1, n1));
    arrMap.insert(make_pair(2, n2));
    arrMap.insert(make_pair(3, n3));
    
    for(auto it = arrMap.begin(); it!=arrMap.end();it++){
        cout<<"Key: "<<it->first<<" : Value : ";
        for(int i=0;i<(it->second).size();i++) cout<<(it->second)[i]<<" ";
    }

    // Multimap allows duplicate keys
    // mlMap[10]=100; is not allowed in multimap
    // Hence we use insert function to add key-value pairs
    multimap<int, int> mlMap;
    mlMap.insert(make_pair(10,100));
    mlMap.insert(make_pair(20,200));
    mlMap.insert(make_pair(10,300));
    mlMap.insert(make_pair(30,400));

    cout<<"\nAll key val pairs in the multimap:"<<endl;
    for(auto it = mlMap.begin();it!=mlMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    return 0;
}