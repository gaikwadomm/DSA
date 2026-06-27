#include<bits/stdc++.h>
using namespace std;

void build(int idx, int low, int high, vector<int>& seg, vector<int>& arr){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }

    int mid = low + (high-low)/2;
    build(2*idx+1, low, mid, seg, arr);
    build(2*idx+2, mid+1, high, seg, arr);

    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}



void updateSeg(int idx, int low, int high, int& l, int& r, vector<int>& seg, vector<int>& lazy, int& val){
    if(lazy[idx]!=0){
        seg[idx] += (high-low+1)*lazy[idx];

        if(low!=high){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }

        lazy[idx]=0;
    }
    if(low>=l && high<=r){
        int numElm = high-low+1;

        seg[idx] += (val*(numElm));
        if(low!=high){
            lazy[2*idx+1] += val;
            lazy[2*idx+2] += val;
        }
        return;
    }

    if(high<l || low>r) return;

    int mid = low + (high-low)/2;
    updateSeg(2*idx+1, low, mid, l, r, seg, lazy, val);
    updateSeg(2*idx+2, mid+1, high, l, r, seg, lazy, val);

    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}


int main(){

}