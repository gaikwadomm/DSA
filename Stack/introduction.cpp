#include<iostream>
#include<vector>
using namespace std;

//Implement with array
class stack{
    int top;
    int size;
    int *arr;

    public:
    bool flag;
    stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
    }   

    void push(int value){
        if(top == size-1){
            cout<<"Stack overflow\n";
            return;
        } else{
            top++;
            arr[top] = value;
            cout<<"Push stack : "<<arr[top]<<endl;
            flag = 0;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"Stack underflow\n";
            return;
        }
        cout<<"Popped "<<arr[top]<<" from arr.\n";
        top--;   
        if(top==-1) flag = 1;
    }

    int peek(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return -1;
        }
        else{
            return arr[top];
        }
    }

    bool IsEmpty(){
        return top==-1;
    }

    int IsSize(){
        return top+1;
    }
};

int main(){
    stack s(5);
    s.push(-1);
    int val = s.peek();

    if(s.flag == 0){
        cout<<"The peek val is "<<val<<endl;
    }
}