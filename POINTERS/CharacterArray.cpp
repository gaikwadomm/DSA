// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

//vector, string reference help
//int arr, char arr pointer ki help se solve karna

void increment(int &num){
    num++;
}
void doubleArr(int *arr){
    for(int i=0;i<5;i++) arr[i]=arr[i]*2;
}

void doubleArr2(int arr[]){
    for(int i=0;i<5;i++) arr[i]=arr[i]*2;
}
void doubleArr3(int (&arr)[5]){
    for(int i=0;i<5;i++) arr[i]=arr[i]*2;
}

//pass by pointer
void swapping(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//pass by reference 
void swapping2(int &p1, int &p2){
    int temp = p1;
    p1 = p2;
    p2 = temp;
}


int main() {
    // Write C++ code here
    char arr[5] = "1234";
    char *ptr = arr;
    cout<<(void *)arr<<endl; //type casting is done. Char pointer is converted to void pointer
    //(void *) indicates the position but dont tell the type of data it stores
    cout<<(void *)ptr<<endl;

    char name = 'a';
    ptr = &name;
    cout<<name<<endl;
    cout<<(void *)ptr<<endl;

    int n = 10;
    increment(n);
    cout<<n<<endl;
    int arr2[5] = {1,2,3,4,5};
    doubleArr(arr2);
    doubleArr2(arr2);
    doubleArr3(arr2);
    for(int i=0;i<5;i++) cout<<arr2[i]<<" ";

    int p1 = 10, p2 = 20;
    swapping(&p1, &p2);
    cout<<endl<<p1<<" "<<p2;

    swapping2(p1, p2);
    cout<<endl<<p1<<" "<<p2;

    return 0;
}