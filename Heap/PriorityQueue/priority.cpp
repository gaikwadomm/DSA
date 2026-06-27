#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    priority_queue<int> p;   //Max Heap

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(10);
    p.push(15);

    cout<<"Max or Top element : "<<p.top()<<endl;

    //Delete 
    p.pop();
    cout<<"Max or Top element : "<<p.top()<<endl;

    //Size 
    cout<<p.size()<<endl;

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }

    priority_queue<int, vector<int>, greater<int>> q;  //Min Heap
    q.push(10);
    q.push(20);
    q.push(11);
    q.push(10);
    q.push(15);

    cout<<"Max or Top element : "<<q.top()<<endl;

    //Delete 
    q.pop();
    cout<<"Max or Top element : "<<q.top()<<endl;

    //Size 
    cout<<q.size()<<endl;

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}