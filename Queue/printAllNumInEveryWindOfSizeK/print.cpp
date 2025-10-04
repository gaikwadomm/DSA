#include<iostream>
#include<queue>
using namespace std;

void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    vector<int> v = {3,6,2,8,7,11};
    int k = 3;

    for(int i=0;i<k-1;i++) q.push(v[i]);

    for(int i=k-1;i<v.size();i++){
        q.push(v[i]);
        display(q);
        q.pop();
    }
}