#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        Node *slow = head;
        Node *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                if(slow==head){
                    while(fast->next != head){
                        fast = fast->next;
                    }
                    fast->next = NULL;
                    return;
                }
                Node *temp = head;
                while(temp->next!=slow->next){
                    slow = slow->next;
                    temp = temp->next;
                }
                slow->next = NULL;
                break;
            }
        }
    }
};



