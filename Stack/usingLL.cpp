#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack{
    int size;
    Node *top;
    public:
    Stack(){
        size = 0;
        top = NULL;
    }

    void push(int val){
        Node *temp = new Node(val);
        if(!temp){
            cout<<"Stack overflow\n";
            return;
        }
        temp->next = top;
        top = temp;
        cout<<temp->data<<" get pushed.\n";
        size++;
    }

    void pop(){
        if(!top){
            cout<<"Stack underflow\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        cout<<temp->data<<" get deleted.\n";
        delete temp;
        size--;
    }

    int peek(){
        if(!top){
            cout<<"Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    bool IsEmpty(){
        return top == NULL;
    }

    int IsSize(){
        return size;
    }
};

int main(){
    // Stack s;
    // s.push(6);
    // s.push(6);
    // s.push(6);
    // s.push(6);
    // s.push(6);
    // s.push(6);
    // cout<<s.IsSize();

    stack<int> s;
    s.push(7);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    // cout<<s.top()<<endl;
}