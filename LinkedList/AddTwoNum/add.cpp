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
    Node* reverseList(Node *head){
        Node *ptr = head;
        Node *prev = NULL;
        while(ptr){
            Node *temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            head = prev;
            ptr = temp;
        }
        return head;
    }
    
    Node *removeLeadingZero(Node *head){
        while(head && head->data == 0 && head->next){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node *p1 = reverseList(head1);
        Node *p2 = reverseList(head2);
        
        Node *head = NULL, *tail = NULL;
        int carry = 0;
        
        while(p1 && p2){
            int sum = p1->data + p2->data + carry;
            if(!head){
                Node *newNode = new Node(sum%10);
                head = tail = newNode;
                carry = sum / 10;
                p1 = p1->next;
                p2 = p2->next;
                continue;
            }
            Node *newNode = new Node(sum%10);
            carry = sum / 10;
            tail->next = newNode;
            tail = tail->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1){
            int sum = p1->data + carry;
            Node *newNode = new Node(sum%10);
            tail->next = newNode;
            tail = tail->next;
            p1 = p1->next;
        }
        
        while(p2){
            int sum = p2->data + carry;
            Node *newNode = new Node(sum%10);
            tail->next = newNode;
            tail = tail->next;
            p2 = p2->next;
        }
        
        while(carry){
            tail->next = new Node(carry%10);
            tail = tail->next;
            carry /= 10;
        }
        
        head = reverseList(head);
        
        head = removeLeadingZero(head);
        return head;
    }
};