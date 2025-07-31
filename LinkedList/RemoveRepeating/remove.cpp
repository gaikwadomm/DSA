#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next = next;
    }
};

Node *createLink(Node *Head, int n){
    Node *ptr, *newNode, *tail=NULL;
    int num;    
    while(n){
        cout<<"Enter Number : ";
        cin>>num;
        newNode = new Node(num);
        if(Head==NULL){
            newNode->next = NULL;
            Head = newNode;
            tail = Head;
        } else{
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        n--;
    }
    return Head;
}

Node *removeKth(Node *head, int k){
    if(!head || k==0) return head;
    Node *ptr = head, *prev=NULL, *ans;
    int count = 1;
    while(ptr){
        if(count%k==0){
            Node *temp = ptr;
            prev->next = ptr->next;
            ptr=ptr->next;
            delete temp;
        } else{
        prev = ptr;
        ptr = ptr->next;
    }
    count++; 
    }
    if(count==1 && k==1){
        delete head;
        return NULL;
    }
    return head;
}

void displayLL(Node *Head){
    if(Head==NULL){
        cout<<"Link list is empty...\n";
        return;
    }
    Node *temp = Head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

}