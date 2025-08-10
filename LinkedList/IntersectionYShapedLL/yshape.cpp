#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node *h1 = head1;
        Node *h2 = head2;
        int c1 = 1, c2 = 1;
        
        while(h1->next){
            c1++;
            h1 = h1->next;
        }
        while(h2->next){
            c2++;
            h2 = h2->next;
        }

        h1=head1;
        h2=head2;
        
        if(c1>c2){
            for(int i=0;i<c1-c2;i++){
                h1=h1->next;
            }
        }
        
        if(c2>c1){
            for(int i=0;i<c2-c1;i++){
                h2=h2->next;
            }
        }
        
        while(h1->next!=h2->next){
            h1 = h1->next;
            h2 = h2->next;
        }
        
        return h1->next;
        
    }
};