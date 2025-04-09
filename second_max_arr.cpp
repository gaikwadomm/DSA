#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>

using namespace std;

int main(){
    srand(time(0));
    int size=9;
    int arr[size];

    for(int i=0;i<size;i++){
        arr[i]=rand() % 100;
    }

    cout<<"The array is ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = INT_MIN,second_max;
    for(int i =0;i<size;i++){
        if(arr[i]>max){
            second_max = max;
            max = arr[i];
        }
    }
    cout<<"The max in the array is "<<max<<endl;
    cout<<"The second max in the array is "<<second_max;

    return 0;
}