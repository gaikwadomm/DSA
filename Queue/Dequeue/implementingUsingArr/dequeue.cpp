#include<iostream>
using namespace std;

class dequeue{
    int front, rear, size;
    int *arr;
    public:
    dequeue(int n){
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool isEmpty(){
        return front==-1;
    }

    bool isFull(){
        return (rear+1)%size == front;
    }

    void push_front(int x){
        if(isFull()){
            cout<<"Dequeue is full\n";
            return;
        }
        if(front==-1){
            front = rear = 0;
            arr[front] = x;
            cout<<x<<" get push in front\n";
            return;
        }
        
        front = (front-1+size)%size;
        arr[front] = x;
        cout<<x<<" get push in front\n";
    }

    void push_back(int x){
        if(isFull()){
            cout<<"Dequeue is full\n";
            return;
        }
        if(rear==-1){
            front = rear = 0;
            arr[rear] = x;
            cout<<x<<" get push in rear\n";
            return;
        }

        rear = (rear+1)%size;
        arr[rear] = x;
        cout<<x<<" get push in rear\n";
    }

    void pop_front(){
        if(isEmpty()){
            cout<<"Dequeue is empty\n";
            return;
        }
        cout<<arr[front]<<" get pop\n";
        if(front==rear){
            front=rear=-1;
            return;
        }
        front = (front+1)%size;
    }

    void pop_rear(){
        if(isEmpty()){
            cout<<"Dequeue is empty\n";
            return;
        }
        cout<<arr[rear]<<" get pop\n";
        if(front==rear){
            front = rear = -1;
            return;
        }
        rear = (rear-1+size) % size;
    }

    void display(){
        if(isEmpty()){
            cout<<"The dequeue is empty\n";
            return;
        }
        int temp = front;
        while(temp!=rear){
            cout<<arr[temp]<<" ";
            temp = (temp+1)%size;
        }
        cout<<arr[rear]<<endl;
    }
};

int main(){
    dequeue d(9);
    d.display();
    d.push_front(1);
    d.push_front(0);
    d.push_back(2);
    d.push_back(3);
    d.pop_rear();
    d.display();
    d.push_front(1);
    d.push_front(1);
    d.push_front(1);
    d.push_front(1);
    d.push_front(1);
    d.push_front(1);
    d.push_front(1);
    d.push_front(1);
}