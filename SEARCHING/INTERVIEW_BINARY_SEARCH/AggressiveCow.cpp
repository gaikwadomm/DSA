// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
// Input: stalls[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
// Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
// Output: 1
// Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
// The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
// Constraints:
// 2 <= stalls.size() <= 106
// 0 <= stalls[i] <= 108
// 2 <= k <= stalls.size()

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
