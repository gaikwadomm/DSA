#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int cow(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    int mid, start = 1, end = arr[arr.size()-1] - arr[0],ans;
    while(start<=end){
        mid = start + (end-start)/2;
        int posi = arr[0],cow=1;
        for(int i=1;i<arr.size();i++){
            if(posi+mid<=arr[i]){
                cow++;
                posi = arr[i];
            }
        }
        if(cow<k){
            end = mid - 1; 
            cout<<cow<<endl;
        }
        else{
            start = mid + 1;
            ans = mid;
            cout<<ans<<endl;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,4,8,9};
    int n=3;
    int ans = cow(arr,n);
    if(ans!=-1){
        cout<<"The min distance with the max possible one between the cow is "<<ans;
    }
    else{
        cout<<"The answer is not possible...";
    }
    return 0;
}
