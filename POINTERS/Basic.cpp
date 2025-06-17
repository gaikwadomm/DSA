// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    // Write C++ code here
    // int arr[5] = {11,7,8,9,10};
    // int *ptr;
    //Remember vector stores data in heap 
    //Which is not contiguous
    // vector<int> *ptr;
    // for(int i=0;i<5;i++){
    //     ptr[i] = &arr[i];
    // }
    
    // cout<<arr<<endl;
    // cout<<arr+0<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<ptr<<endl;
    
    // cout<<arr+1<<endl;
    
    // cout<<*arr<<endl;
    // cout<<*(arr+1)<<endl;
    
    // for(int i=0;i<5;i++) cout<<*(arr+(i))<<endl;

    // for(int i=0;i<5;i++) cout<<arr+i<<endl;
    
    // ptr = arr;
    
    // for(int i=0;i<5;i++) cout<<ptr[i]<<endl;
    
    // //Also can be done using arethmetic operation like ++ / --
    
    // for(int i=0;i<5;i++){
    //     cout<<*ptr<<endl;
    //     ptr++;
    // }
    
    //NOTE ARETHMETIC OPERATION ARE NOT ALLOWED ON ARR
    //i.e arr++ is not allowed as it stores the constant address of the first element of the array
    //Bcoz in case of ptr we are changing the values (i.e the address stored in it) and not the actuall address of the ptr 
    //And in case of arr++ we are trying to change the address 
    //And address manipulation is not allowed 
    
    char arr[5] = {'1', '2', '3', '4', '5'};
    
    for(int i=0;i<5;i++) cout<<(void *)(arr+i)<<endl;
    for(int i=0;i<5;i++) cout<<(void *)(&arr[i])<<endl;
    
    char name = 'a';
    
    cout<<(void *)(&name);
    return 0;
}