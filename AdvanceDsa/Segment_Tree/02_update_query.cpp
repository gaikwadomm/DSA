#include<bits/stdc++.h>
using namespace std;

int seg[4*7], arr[7];

// Over here the seg tree is storing the sum of the segment
// use for prefix sum
void build(int idx, int low, int high){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }

    int mid = low + (high-low)/2;
    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);

    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}

// Update the seg tree
void update_seg_tree(int idx, int low, int high, int& val, int& updateIdx){
    if(low==high && low==updateIdx){
        seg[idx] = val;
        return;
    }

    int mid = low + (high-low)/2;
    if(updateIdx<=mid){
        update_seg_tree(2*idx+1, low, mid, val, updateIdx);
    }
    else{
        update_seg_tree(2*idx+2, mid+1, high, val, updateIdx);
    }

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int main(){
    int n;
    cout<<"Enter Size : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter idx "<<i<<" : ";
        cin>>arr[i];
    }

    build(0, 0, n-1);

    for(int i=0;i<28;i++){
        cout<<"Seg "<<i<<" : "<<seg[i]<<endl;
    }

    int updIdx;
    cout<<"Update idx : ";
    cin>>updIdx;

    int val;
    cout<<"Val : ";
    cin>>val;

    update_seg_tree(0, 0, n-1, val, updIdx);

    for(int i=0;i<28;i++){
        cout<<"Seg "<<i<<" : "<<seg[i]<<endl;
    }
}