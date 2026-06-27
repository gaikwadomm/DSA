#include<iostream>
#include<unordered_map>
using namespace std;

// It stores data in key-value pair format
// Keys are unique, and values can be duplicated
// Implemented using Hash Tables
// Time Complexity: O(1) on average for insertion, deletion, and search operations
// Unique keys are present but in no particular order

int main(){
    unordered_map<int, int> mlMap;
    mlMap.insert(make_pair(10,100));
    mlMap.insert(make_pair(20,200));
    mlMap.insert(make_pair(10,300));
    mlMap.insert(make_pair(30,400));

    cout<<"\nAll key val pairs in the Unordered Map:"<<endl;
    for(auto it = mlMap.begin();it!=mlMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    unordered_multimap<int, int> umMap;
    umMap.insert(make_pair(10,100));
    umMap.insert(make_pair(20,200));
    umMap.insert(make_pair(10,300));
    umMap.insert(make_pair(30,400));

    cout<<"\nAll key val pairs in the Unordered MultiMap:"<<endl;
    for(auto it = umMap.begin();it!=umMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}