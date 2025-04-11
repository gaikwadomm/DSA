#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int PeakIndex(vector<int> arr){
    int mid,start = 0, end = arr.size()-1,largest=INT_MIN;
    while(start<=end){
        mid = end+(start-end)/2;
        if((arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])){
            cout<<start<<" "<<end<<endl;
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            start = mid + 1;
            cout<<"Start "<<start<<endl;
        }
        else{
            end = mid - 1; 
            cout<<"End "<<end<<endl;
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the arrays : \n";
    for(int i = 0;i<size;i++){
        cout<<"Enter "<<i<<" element : ";
        cin>>arr[i];
    }

    cout<<"The peak is at "<<PeakIndex(arr);
}