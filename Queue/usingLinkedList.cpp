#include<iostream>
using namespace std;
class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
    Node *front;
    Node *rear;
    int count=0;
    myQueue() {
        // Initialize your data members
        front = rear = nullptr;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==nullptr;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        if(isEmpty()){
            front = new Node(x);
            rear = front;
            count++;
            return;
        } else{
            rear->next = new Node(x);
            rear = rear->next;
        }
        count++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) return;
        Node *temp = front;
        front = front->next;
        delete temp;
        count--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) return -1;
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return count;
    }
};
