// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int minEatingSpeed(vector<int> piles, int h) {
    int mid ,start = 1, end = *max_element(piles.begin(), piles.end()), ans;
    // int mid ,start = 0, end = 0, ans;
    // long long sum=0;
    // for(int i=0;i<piles.size();i++){
    //     sum += piles[i];
    //     end = max(end, piles[i]);
    // }
    // start = sum/h;
    // if(start==0){
    //     start = 1;
    // }
    while(start<=end){
        mid = start + (end-start)/2;
        long long time = 0;
        for(int i =0;i<piles.size();i++){
            time += (piles[i]+mid-1)/mid;
        }
        // int time=0;
        // for(int i =0;i<piles.size();i++){
        //     time += piles[i]/mid;
        //     if(piles[i]%mid){
        //         time++;
        //     }
        // }
        if(time>h){
            start = mid + 1;
        }
        else{
            end = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main(){

}