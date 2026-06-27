#include<bits/stdc++.h>
using namespace std;

int seg[4*10000], arr[10000];

void build(int idx, int low, int high){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }

    int mid = low + (high -  low)/2;
    build(2*idx + 1, low, mid);
    build(2*idx + 2, mid+1, high);
    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
}

int solve(int idx, int l, int r, int& low, int& high){
    if(l>=low && r<=high){
        return seg[idx];
    }
    if(r<low || l>high){
        return INT_MIN;
    }

    int mid = l + (r-l)/2;
    int left = solve(2*idx+1, l, mid, low, high);
    int right = solve(2*idx+2, mid+1, r, low, high);

    return max(left, right);
}

int main(){
    int n;
    cout<<"Enter Size of Arr : ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout<<"Enter idx "<<i<<" : ";
        cin>>arr[i];
    }

    build(0, 0, n-1);

    int q;
    cout<<"Enter Number of Queries : ";
    cin>>q;

    while(q--){
        int l,r;
        cout<<"Enter l = ";
        cin>>l;
        cout<<"Enter r = ";
        cin>>r;
        cout<<"Max for the range : ( "<<l<<", "<<r<<" ) is "<<solve(0, 0, n-1, l, r);
    }

    return 0;
}