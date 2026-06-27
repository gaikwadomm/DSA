#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    l.push_back(4); 
    l.push_back(5); 
    l.push_back(6); 
    l.push_back(7); 
    l.push_back(8);
    l.push_front(3); 
    l.push_front(2); 
    l.push_front(1);
    l.push_front(1);
    l.pop_front();

    cout<<l.front()<<" "<<l.back()<<endl;
    cout<<l.size()<<" "<<endl;

    //Iterator
    for(auto it = l.begin(); it!=l.end(); it++){
        cout<<*it<<" ";
    }
    // for(list<int>::iterator it = l.begin(); it!=l.end(); it++){
    //     cout<<*it<<" ";
    // }
    for(auto it = l.rbegin(); it!=l.rend(); it++){
        cout<<*it<<" ";
    }
}