#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};


Node *insertEnd(Node *Head, int n){
    Node *ptr, *newNode, *tail=NULL, *prev = NULL;
    int num;    
    while(n){
        cout<<"Enter Number : ";
        cin>>num;
        newNode = new Node(num);
        if(Head==NULL){
            newNode->next = NULL;
            newNode->prev = NULL;
            Head = newNode;
            tail = Head;
        } else{
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = NULL;
            tail = newNode;
        }
        n--;
    }
    return Head;
}

Node *insertEndRec(Node* head, Node* prevNode, int n){
    if(!n){
        return head;
    } 
    Node *prev, * next;
    int num;
    cout<<"Enter Number : ";
    cin>>num;
    Node *newNode = new Node(num);
    if(prevNode==NULL && head==NULL){
        head = newNode;
        head->prev = NULL;
        head->next = NULL;
    } else{
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = NULL;
}
    insertEndRec(head, newNode, n-1);
}

Node *insertStart(Node *Head, int n){
    Node *ptr, *newNode, *prev = NULL;
    int num;
    while(n){
        cout<<"Enter Number : ";
        cin>>num;
        newNode = new Node(num);
        if(Head==NULL){
            newNode->next = NULL;
            newNode->prev = NULL;
            Head = newNode;
        } else{
            Head->prev = newNode;
            newNode->next = Head;
            newNode->prev = NULL;
            Head = newNode;
        }
        n--;
    }
    return Head;
}

//Insert after the node 
Node *insertionAtAny(Node *head, int n){
    if(!head) return head;
    
    Node *ptr = head;
    for(int i=1;i<n;i++){
        if(ptr->next == NULL) return head;
        ptr = ptr->next;
    }

    cout<<ptr->next;
    int num;
    cout<<"Enter Number : ";
    cin>>num;
    Node *newNode = new Node(num);

    if(n==0){
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = head;
        head = newNode;
        return head;
    }

    Node *nextNode = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    if(nextNode == NULL){
        newNode->next = NULL;
    } else{
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    return head;
}

Node *deleteStart(Node *head){
    if(!head) return head;
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

Node *deleteEnd(Node *head){
    if(!head) return head;
    if(head->next == NULL && head->prev==NULL){
        delete head;
        return NULL;
    }

    Node *curr = head;
    while(curr->next){
        curr = curr->next;
    }

    curr->prev->next = NULL;
    delete curr;
    return head;
}

Node *deleteAtAny(Node *head, int n){
    if(!head || !n) return head;

    if(n==1){
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }

    Node *curr = head;
    for(int i=1;i<n;i++){
        if(!curr->next){
            return head;
        }
        curr = curr->next;
    }

    if(!curr->next){
        curr->prev->next = NULL;
        delete curr;
        return head;
    }

    Node *prevNode = curr->prev;
    prevNode->next = curr->next;
    curr->next->prev = prevNode;
    delete curr;
    
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

    Node *Head = insertEnd(NULL, n);
    displayLL(Head);

    Head = deleteStart(Head);
    displayLL(Head);

    Head = deleteEnd(Head);
    displayLL(Head);

    Head = deleteAtAny(Head, 3);
    displayLL(Head);

    // cout<<"Enter the Node after which to insert : ";
    // cin>>n;

    // Head = insertionAtAny(Head, n);
    // displayLL(Head);

    // cout<<"Enter Number of data : ";
    // cin>>n;
    // Head = insertStart(Head, n);
    // displayLL(Head);

    // Node *Head;
    // cout<<"Enter Number of data : ";
    // cin>>n;
    // Head = insertEndRec(NULL, NULL,n);
    // displayLL(Head);
}