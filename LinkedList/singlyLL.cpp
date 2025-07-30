#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *Head = NULL;

int main(){
    int n;
    // cout<<"Enter Number of data : ";
    // cin>>n;
    // for(int i=0;i<n;i++){ 
    //     int val;
    //     cout<<"Enter Number : ";
    //     cin>>val;
    //     if(Head==NULL){       
    //         Head = new Node(val);
    //     } else{
    //         Node *temp;
    //         temp = new Node(val);
    //         temp->next = Head;
    //         Head = temp;
    //     }
    // }

    // Node *temp = Head;
    // while(temp!=NULL){
    //     cout<<temp->data<<"->";
    //     temp = temp->next;
    // }

    cout<<"Enter Number of data : ";
    cin>>n;
    Node *tail = NULL;
    for(int i=0;i<n;i++){ 
        int val;
        cout<<"Enter Number : ";
        cin>>val;
        if(Head==NULL){       
            Head = new Node(val);
            tail = Head;
        } else{
            // Node *newNode, *ptr=Head;
            // newNode = new Node(val);
            // while(ptr->next != NULL){
            //     ptr=ptr->next;
            // }
            // ptr->next = newNode;
            //  newNode->next = NULL;
            tail->next = new Node(val);
            tail = tail->next;
        }
    }

    Node *temp = Head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}