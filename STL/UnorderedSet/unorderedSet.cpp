#include<iostream>
#include<unordered_set>
using namespace std;

//It contain only unique elements in no particular order
//Search, insertion, and deletion have average time complexity of O(1)
//It uses hashing technique to achieve constant time complexity

int main(){
    unordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20); // Duplicate, will not be added
    s.insert(40);
    s.insert(50);

    cout << "Elements in the unordered_set:" << endl;
    for(auto it=s.begin(); it!=s.end();it++){
        cout<<*it<<" ";
    }

    s.erase(30);
    cout << "\nElements after erasing 30:" << endl;
    for(auto it=s.begin(); it!=s.end();it++){
        cout<<*it<<" ";
    }   

    s.clear();
    cout << "\nSize after clearing the unordered_set: " << s.size() << endl;

    unordered_multiset<int> ms={10, 20, 20, 30, 40, 40, 50};
    cout << "Elements in the unordered_multiset:" << endl;
    for(auto it=ms.begin(); it!=ms.end();it++){
        cout<<*it<<" ";
    }
}