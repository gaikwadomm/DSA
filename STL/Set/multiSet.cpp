#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    //In multiset duplicate elements are allowed
    //Elements are stored in sorted order
    //Underlying data structure is balanced BST
    multiset<int>ms;
    //insert
    ms.insert(7);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);

    for(auto it=ms.begin();it!=ms.end();it++) cout<<*it<<" ";

    //Search
    if(ms.find(7)!=ms.end()) cout<<endl<<7<<" present.";

    cout<<endl<<ms.count(2);

    ms.insert(71);
    ms.insert(71);
    ms.erase(71);
    cout<<endl<<ms.count(71)<<endl;
}