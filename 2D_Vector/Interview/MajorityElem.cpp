//Give the array containing the number in 1 to N
//N is the size of the array 
//Find the number thats appear more than N /2 times

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>arr) {
        int n = arr.size(), ans=0, candidate=arr[0], count=1;
        // for(int i=0;i<n;i++){
        //     if(count == 0){
        //         count += 1;
        //         candidate = arr[i];
        //     }
        //     else{
        //         if(candidate == arr[i]){
        //             count += 1;
        //         }
        //         else{
        //             count--;
        //         }
        //     }
        // }

        for(int i=1;i<n;i++){
            if(candidate == arr[i]){
                count += 1;
            }
            else{
                count--;
                if(count<0){
                    count = 1;
                    candidate = arr[i];
                }
            }
        }

        return candidate;
    }

int main(){
    cout<<"The Majority Number is "<<majorityElement({3,3,2,3,1,3,2,2,1,3,3});
}
