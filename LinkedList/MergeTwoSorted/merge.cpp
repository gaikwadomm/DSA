//  Definition for singly-linked list.
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // code here
        ListNode *h1=list1, *h2=list2, *tail=NULL;
        ListNode *head=NULL;
        while(h1&&h2){
            if(h1->val <= h2->val){
                if(!head){
                    head = h1;
                    tail = h1;
                } else{
                    tail->next = h1;
                    tail = h1;
                }
                h1=h1->next;
            } else{
                if(!head){
                    head = h2;
                    tail = h2;
                } else{
                    tail->next = h2;
                    tail = h2;
                }
                h2=h2->next;
            }
        }
        if( h1){ 
            if(!head) return h1;
            tail->next = h1;
        };
        if(h2){
            if(!head) return h2;
            tail->next = h2;
        };
        
        return head;
    }
};