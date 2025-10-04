#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class dequeue{
    Node *front, *rear;
    public:
    dequeue(){
        front = rear = NULL;
    }
    void push_front(int x){
      if(front==NULL && rear==NULL){
        front = rear = new Node(x);
        return;
      }  
      Node *temp = new Node(x);
      temp->next = front;
      front->prev = temp;
      front = temp;
    }

    void push_back(int x){
        if(front==NULL && rear==NULL){
            front = rear = new Node(x);
            return;
        }
        Node *temp = new Node(x);
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }

    void pop_front(){
        if(front==NULL && rear==NULL){
            cout<<"The dequeue is empty\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if(front==NULL) rear = NULL;
        else front->prev = NULL;
        cout<<temp->data<<" get deleted\n";
        delete temp;
    }

    void pop_back(){
        if(front==NULL && rear==NULL){
            cout<<"The dequeue is empty\n";
            return;
        }

        Node *temp = rear;
        rear = temp->prev;
        if(rear==NULL) front=NULL;
        else rear->next=NULL;
        cout<<temp->data<<" get deleted\n";
        delete temp;
    }

    int start(){
        if(front==NULL && rear==NULL){
            cout<<"Dequeue is empty\n";
            return -1;
        }
        return front->data;
    }

    int end(){
        if(front==NULL && rear==NULL){
            cout<<"Dequeue is empty\n";
            return -1;
        }
        return rear->data;
    }

    void display(){
        if(front==NULL){
            cout<<"The dequeue is empty\n";
            return;
        }

        Node *temp = front;

        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    dequeue d;
    d.push_front(7);
    d.push_back(1);
    d.push_back(0);
    d.display();
    d.pop_back();
    d.display();
    d.push_front(1);
    d.display();
}