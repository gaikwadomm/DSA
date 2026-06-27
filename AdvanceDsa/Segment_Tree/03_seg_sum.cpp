#include<bits/stdc++.h>
using namespace std;

int seg[4*10000], arr[10000];

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

int solve(int idx, int low, int high, int& l, int& r){
    if(low>=l && high<=r) return seg[idx];

    if(high<l || low>r) return 0;

    int mid = low + (high-low)/2;

    int left = solve(2*idx + 1, low, mid, l, r);
    int right = solve(2*idx + 2, mid+1, high, l, r);

    return left + right;
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

    int q;
    cout<<"Enter Number of Queries : ";
    cin>>q;

    while(q--){
        int l, r;
        cout<<"Enter l = ";
        cin>>l;
        cout<<"Enter r = ";
        cin>>r;
        cout<<"Sum from range ( "<<l<<", "<<r<<" ) : "<<solve(0, 0, n-1, l, r)<<endl;
    }
}