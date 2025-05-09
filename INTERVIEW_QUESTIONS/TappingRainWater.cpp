#include<iostream>
#include<climits>
#include<vector>
using namespace std;

//The Time Complexity of below code is O(N)
//And the space Complexity is O(N)
int TappingRainWater(vector<int> building){
    int n = building.size(), TotalWater=0;
    vector<int> maxLeft(n), maxRight(n);
    maxLeft[0]=0;
    for(int i=1;i<n;i++){
        maxLeft[i] = max(building[i-1], maxLeft[i-1]);
    }
    maxRight[n-1]=0;
    for(int i=n-2;i>0;i--){
        maxRight[i] = max(building[i+1], maxRight[i+1]);
    }
    int mini, waterStored;
    for(int i=0;i<n;i++){
        mini = min(maxLeft[i], maxRight[i]);
        waterStored = mini - building[i];
        if(waterStored<=0){
            TotalWater+=0;
        }
        else{
            TotalWater += waterStored;
        }
    }
    return TotalWater;
}

int ReduceSpaceComplexityTappingRainWater(vector<int> building){
    int tallest=0, n=building.size(), water=0;
    for(int i=0;i<n;i++){
        if(building[i]>building[tallest]){
            tallest=i;
        }
    }
    int leftMax = 0;
    for(int i=1;i<tallest;i++){
        leftMax = max(leftMax, building[i-1]);
        if(leftMax>building[i]){
            water += leftMax - building[i];
        }
    }
    int rightMax = 0;
    for(int i=n-2;i>tallest;i--){
        rightMax = max(rightMax, building[i+1]);
        if(rightMax>building[i]){
            water += rightMax - building[i];
        }
    }
    return water;
}

int main(){
    cout<<"The water that can be stored "<<TappingRainWater({4,2,0,5,2,6,2,3})<<"\n";
    cout<<"The water that can be stored "<<ReduceSpaceComplexityTappingRainWater({4,2,0,5,2,6,2,3});
}

// int TappingRainWater(vector<int> building){
//     int start = 0;
//     int end = start + 1, water = 0;
//     while(start < building.size()){
//         end = start + 1;
//         while(end < building.size() && building[start] < building[end]){
//             water += (building[end] - building[start]);
//             end++;
//         }
//         if(end >= building.size()) break;
//         start = end;
//     }
//     return water;
// }