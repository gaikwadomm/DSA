#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    unordered_map<Node *, Node *> mapList;
    Node *cloneLinkedList(Node *head) {
        // code here
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;
        
        while(temp){
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            mapList[temp] = tailCopy;
            temp = temp->next;
        }
        
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        
        tailCopy = headCopy;
        temp = head;
        
        while(temp){
            if(temp->random) tailCopy->random = mapList[temp->random];
            temp = temp->next;
            tailCopy = tailCopy->next;
        }
        
        return headCopy;
    }
};
