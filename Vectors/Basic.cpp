//Vector memory is allocated in heap and for array it is allocated in stack
//Heap is very large in size and stack is very fast 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> a={1,2,3,4,5,6,17,8,9};
    // a.push_back(5);
    // a.pop_back(); O(1)
    //a.clear(); To clear the entire vector
    //a.erase(a.begin()+2); Erasing the memory at index 2   O(n)
    //a.front(); Output : Startine element
    //a.back(); Output : Last element
    //a.empty();   true if a is empty else false
    //a.capacity();

    sort(a.begin(),a.end());
    for(auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<binary_search(a.begin(),a.end(),17);
    cout<<endl;
    cout<<find(a.begin(),a.end(),17)-a.begin();
    cout<<endl;
    a.insert(a.begin()+1,7);
    for(auto i : a){
        cout<<i<<" ";
    }


}