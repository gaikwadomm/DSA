#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int search(int arr[], int n, int size){
    for(int i = 0;i<size;i++){
        if(n==arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int flag,n;
    srand(time(0));
    int arr[10];

    for(int i=0;i<10;i++){
        arr[i]=rand() % 100;
    }

    cout<<"The array is ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<<endl<<"Enter the number to search : ";
    cin>>n;

    flag=search(arr,n,10);
    if(flag!=-1){
        cout<<"The element "<<n<<" is present at "<<flag;
    }
    else{
        cout<<"The element is not present in the array.";
    }
}