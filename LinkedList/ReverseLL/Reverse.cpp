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

Node *reverseLinkList(Node *Head){
    Node *curr = Head, *prePtr = NULL;
    Node *nextNode = curr;
    while(nextNode){
        nextNode = curr->next;
        curr->next = prePtr;
        prePtr = curr;
        Head = prePtr;
        curr = nextNode;
    }
    return Head;
}

Node *reverseLinkListRecursion(Node *curr, Node *prev){
    if(curr == NULL){
        return prev;
    }
    Node *temp = curr->next;
    curr->next = prev;
    reverseLinkListRecursion(temp, curr);
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

    Head = reverseLinkList(Head);
    displayLL(Head);
    Head = reverseLinkList(Head);
    displayLL(Head);
    Head = reverseLinkList(Head);
    displayLL(Head);
    Head = reverseLinkList(Head);
    displayLL(Head);
}