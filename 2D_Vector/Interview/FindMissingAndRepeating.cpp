#include<iostream>
#include<vector>
using namespace std;


//Optimal way without creating the extra array
void findMissingAndRepeating(vector<int> arr){
    int n = arr.size();
    //First decrease all the num of arr by 1
    for(int i=0;i<n;i++){
        arr[i]-=1;
    }

    //ek se isliye ghatay ki agae index pe jane mai asani ho 
    //Now we will make the arr
    //in such way that it will store two things 
    //Ek to konsa element hai usme vo and vo elem kitni bar aya hai vo
    //as we know that for that 
    //if we have to store two numbers at a single place 
    //and want them in future than we can do one thing
    //i.e stored = num_1 + num_2*(till what it can hold + 1) like if we can hold 1 to 7 than it will be 8
    //so in this case we say original_num + number_of_times_repeated * n (as 0 to n-1 is there) 
    for(int i=0;i<n;i++){
        int index = arr[i]%n; //index find kiya jaha pe jana hai                              
        arr[index] += n;
        //us index pe jakar n add karne se 
        //ham use ye bata rahe hai ki tum 
        //ek bar aye ho
        //vapas add karne pe bata rahi hai ki tum vapas 
        //ek bar aye ho 
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    //abhi array mai jo store number hai vo bata rahe hai do chezze
    //paheli ki usme jo actuall number store tha 
    //and dusri vo number kitne bar repeat hua 
    //stored = actuall_number + repeated*n
    
    //actuall_number = stored % n
    //repeated = stroed / n
    int missing, repeated_num;
    for(int i=0;i<n;i++){
        int count = arr[i] / n;
        if(count==0){
            missing = i + 1;
        }
        if(count==2){
            repeated_num = i + 1;
        }
    }
    cout<<"The missing number is "<<missing<<" and the repeated number is "<<repeated_num<<".";
}

void find(vector<int> arr, int n){
    vector<int> count(n,0);
    int num, missing, repeating;
    for(int i=0;i<n;i++){
        num = arr[i];
        count[num-1] += 1;
    }
    // cout<<"The count Array is : ";
    // for(int i=0;i<n;i++){
    //     cout<<count[i]<<" ";
    // }
    for(int i=0;i<n;i++){
        if(count[i]>1){
            repeating = i+1;
        } 
        if(count[i]==0){
            missing = i+1;
        }
    }
    cout<<"The missing number is "<<missing<<" and the repeated number is "<<repeating<<".";
}


int main(){
    findMissingAndRepeating({4,3,2,1,2,7,6});
    find({4,3,2,1,2,7,6}, 7);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

// int repeat = 0, count=1, sumArrElem = 0, actualSumOfn = 0;

// //To find the repeated number 
// for(int i=0;i<n;i++){
//     if(repeat == arr[i]){
//         break;
//     }   
//     else{
//         repeat = arr[i];
//     }
// }

// //To find the missing number
// for(int i=0;i<n;i++){
//     sumArrElem+=arr[i];
//     actualSumOfn += (i+1);
// }
// sumArrElem-=repeat;

// int missing = actualSumOfn-sumArrElem;

// cout<<"The missing number is "<<missing<<" the repeated number is "<<repeat<<".";

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
