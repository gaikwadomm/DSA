#include<iostream>
using namespace std;

class MaxHeap{
    int *arr;
    int size; //Total elements in heap
    int total_size; //Total size of array

    public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert into the Heap 
    void insert(int val){
        if(size==total_size){
            cout<<"Heap Overflow\n";
            return;
        }

        int child = size;
        size++;
        //Not needed
        // if(child==0){
        //     arr[child]=val;
        //     return;
        // }
        arr[child] = val;
        int parent = (child-1)/2;
        while(parent>=0 && arr[parent]<arr[child]){
            swap(arr[parent], arr[child]);
            child = parent;
            parent = (child-1)/2;
        }

        cout<<arr[child]<<" is inserted into the heap.\n";
    }

    void Heapify(int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left<size && arr[left]>arr[largest]) largest = left;
        if(right<size && arr[right]>arr[largest]) largest = right;

        if(largest!=index){
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }

    }

    //Only for top node(Max Val of Heap)
    void deleteVal(){
        if(size==0){
            cout<<"Heap is Empty.\n";
            return;
        }
        int lastNode = arr[size-1];
        arr[0] = lastNode;
        size--;

        // Option : 1
        //The operation performed Below is Called as Heapify
        int index = 0;

        while(index<(size-1)/2 && (arr[index]<arr[2*index+1] || arr[index]<arr[2*index+2])){
            int left = 2*index + 1;
            int right = 2*index + 2;

            if(arr[index]<arr[left] && arr[left]>arr[right]){
                swap(arr[left], arr[index]);
                index = left;
            } else if(arr[index]<arr[right] && arr[right]>arr[left]){
                swap(arr[right], arr[index]);
                index = right;
            }
        }

        // Option : 2
        // if(size==0) return;

        // Heapify(0);

        cout<<"Top value get delete successfully.\n";
    }

    void display(){
        if(size==0){
            cout<<"Heap is Empyt.";
            return;
        }
        cout<<"Val in Heap are : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\nAll Val are displayed.\n";
    }
};

// int main(){
//     MaxHeap H1(9);

//     H1.insert(30);
//     // H1.insert(9);
//     // H1.insert(20);
//     // H1.insert(8);
//     // H1.insert(3);
//     // H1.insert(16);
//     // H1.insert(12);
//     // H1.insert(5);
//     // H1.insert(4);

//     H1.display();

//     H1.deleteVal();
//     H1.display();
// }