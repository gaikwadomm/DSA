//  Definition for singly-linked list.
#include<iostream>
//   Node is defined as
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int zero = 0, one = 0, two = 0;
        Node *ptr = head;
        while(ptr){
            if(ptr->data==0){
                zero++;
            }
            else if(ptr->data==1){
                one++;
            }
            else{
                two++;
            }
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            if(zero){
                ptr->data=0;
                zero--;
            } else if(one){
                ptr->data = 1;
                one--;
            } else{
                ptr->data = 2;
                two--;
            }
            ptr = ptr->next;
        }
        return head;
    }
};