#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void SubArrays(vector<int> arr){
    for(int size=1;size<=arr.size();size++){
        for(int subPart=0;subPart<=arr.size()-size;subPart++){
            cout<<"{ ";
            for(int i=subPart;i<subPart+size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"}\n";
        }
    }
}

int main(){
    int size = 4, n;
    vector<int> arr(size);
    srand(time(0));
    for(int i =0;i<size;i++){
        arr[i] = rand() % 100;
    }
    cout<<"The actual array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    SubArrays(arr);

    // sort(arr.begin(), arr.end());


    // cout<<"\nEnter the differen to keep in between : ";
    // cin>>n;
    // pair<int, int> ans = PairDifferBinary(arr, n);
    // cout<<"The answer is "<<ans.first<<" and "<<ans.second;

    return 0;
}