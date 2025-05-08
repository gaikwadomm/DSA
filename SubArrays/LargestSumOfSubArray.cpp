#include<iostream>
#include<vector>
#include<climits>
using namespace std;

pair<int, vector<int>> LargestSum(vector<int> arr){
    int n = arr.size(), sum=0, max = INT_MIN;
    vector<int> ans;
    for(int i=0;i<n;i++){
        vector<int> subArr;
        for(int j=i;j<n;j++){
            sum += arr[j];
            // cout<<sum<<"\n";
            subArr.push_back(arr[j]);
            if(sum>max){
                max=sum;
                ans = subArr;
            }
            
        }
        sum=0;
    }
    return {max, ans};
}

int main(){
    auto result = LargestSum({4,-6,2,8});
    vector<int> ans = result.second;
    int num = result.first;
    cout<<"The Largest Sum is "<<num<<" and the subarray is ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// pair<int, vector<int>> LargestSum(vector<int> arr) {
//     int maxSum = INT_MIN, currentSum = 0;
//     int start = 0, end = 0, tempStart = 0;
//     for (int i = 0; i < arr.size(); i++) {
//         currentSum += arr[i];

//         if (currentSum > maxSum) {
//             maxSum = currentSum;
//             start = tempStart;
//             end = i;
//         }

//         if (currentSum < 0) {
//             currentSum = 0;
//             tempStart = i + 1;
//         }
//     }

//     vector<int> subArray(arr.begin() + start, arr.begin() + end + 1);
//     return {maxSum, subArray};
// }

// int main() {
//     auto result = LargestSum({4, -6, 2, 8});
//     vector<int> ans = result.second;
//     int num = result.first;

//     cout << "The Largest Sum is " << num << " and the subarray is: ";
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
