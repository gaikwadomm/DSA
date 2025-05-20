#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1,0,1};
    vector<vector<int>> qr = {{0,2}};
    int num_zeros = 0;
        for(int i=0;i<qr.size();i++){
            for(int j=qr[i][0];j<=qr[i][1];j++){
                if(nums[j]!=0){
                    nums[j] -= 1;
                    if(nums[j]==0){
                        num_zeros += 1;
                    }    
                }
                else if(nums[j]==0){
                    num_zeros += 1;
                }
            }
        }
        bool ans;
        cout<<"num_zeros"<<num_zeros;

        if(num_zeros == nums.size()){
            ans = true;
        }
        else{
            ans = false;
        }
        cout<<ans;
    for(int i=0;i<3;i++){
        cout<<nums[i];
    }
}
