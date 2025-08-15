#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


class Solution {
  public:
    Node *merge(Node *head1, Node *head2){
        Node *h1 = head1, *h2 = head2;
        Node *head = NULL, *tail = NULL;
        while(h1 && h2){
            if(h1->data<=h2->data){
                if(!head){
                    head = h1;
                    tail = h1;
                } else{
                    tail->next = h1;
                    tail = h1;
                }
                h1 = h1->next;
            } else{
                if(!head){
                    head = h2;
                    tail = h2;
                } else{
                    tail->next = h2;
                    tail = h2;
                }
                h2 = h2->next;
            }
        }
        if(h1) tail->next = h1;
        if(h2) tail->next = h2;
        
        return head;
    }
    
    void mergesort(vector<Node *>& arr, int start, int end){
        if(start>=end) return;
        int mid = start + (end-start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        arr[start] = merge(arr[start], arr[mid+1]);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        mergesort(arr, 0, arr.size()-1);
        return arr[0];
    }
};