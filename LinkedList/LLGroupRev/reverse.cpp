#include<iostream>
using namespace std;

//   Node is defined as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;


class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(!head || k<=1) return head;
        // code here
        Node *first = new Node(0);
        first->next = head;
        head = first;
        
        while(first->next){
            int x = k;
            Node *second = first->next;
            Node *prev = first;
            Node *curr = first->next;
            
            while(x && curr){
                Node *front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                x--;
            }
            
            first->next = prev;
            second->next = curr;
            first = second;
        }
        
        first = head;
        head = head->next;
        delete first;
        
        return head;
    }
};