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

Node *deleteNth(Node* head, int n){
    if(!head || n==0) return head;
    Node *ptr = head;
    int count = 1;
    while(ptr->next){
        count++;
        ptr = ptr->next;
    }
    // cout<<count;
    ptr = head;
    for(int i=1;i<count-n;i++){
        ptr = ptr->next;
    }
    Node *deletingNode = ptr->next;
    ptr->next = deletingNode->next;
    delete deletingNode;
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
    int n;
    cout<<"Enter Number of data : ";
    cin>>n;

    Node *Head = createLink(NULL, n);
    displayLL(Head);

    Head = deleteNth(Head, 2);
    displayLL(Head);
}