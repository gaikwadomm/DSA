#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int target, int start, int end){
    if(start>end){
        return -1;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        end = mid - 1;
    }
    else{
        start = mid + 1;
    }
    return binarySearch(arr, target, start, end);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    cout<<binarySearch(arr, 3, 0, 6);

        // Example usage for the following code:
        vector<int> nums = {1, 5, 3, 4, 2}; // define nums
        int k = 2; // define k
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, ans = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= k) { // check j < n first
                j += 1;
            }
            ans++;
            i = j;
        }
        cout << ans << endl;
        return ans;


}