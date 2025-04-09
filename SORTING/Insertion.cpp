#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
using namespace std;

vector<int> insertion(vector<int> arr){
    int length = arr.size();
    vector<int> ans = arr;

    for(int i=1;i<length;i++){
        int j = i-1, temp = ans[i];
        while(j>=0 && temp<ans[j]){ 
            ans[j+1]=ans[j];
            j -= 1;
        }
        
        ans[j+1] = temp;
    }
    return ans;
}

int main(){
    int size = 10;
    vector<int> arr(size);
    srand(time(0));
    for(int i =0;i<size;i++){
        arr[i] = rand() % 100;
    }

    cout<<"The actual array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    vector<int> ans = insertion(arr);
    cout<<"\nThe sorted array is ";
    for(int i = 0;i<size;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}