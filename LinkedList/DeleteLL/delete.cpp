#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        this->data = val;
        this->next = NULL;
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

Node *deleteFirstNode(Node *Head){
    if(Head==NULL) return NULL;
    Node *ptr = Head;
    Head = Head->next;
    cout<<ptr->data<<" deleted successfully...\n";
    delete ptr;
    return Head;
}
Node *deleteLastNode(Node *Head){
    if(Head==NULL) return NULL;
    if(Head->next == NULL){
    cout<<Head->data<<" deleted successfully...\n";
    delete Head;
    return NULL;
    }
    Node *ptr = Head, *prev = NULL;
    while(ptr->next!=NULL){
        prev = ptr;
        ptr = ptr->next;
    }
    cout<<ptr->data<<" deleted successfully...\n";
    delete ptr;

    // if(prev==NULL){
    //     return NULL;
    // }
    prev->next = NULL;
    return Head;
}

Node *deleteParticularNode(Node *Head, int x){
    if(Head == NULL) return NULL;
    if(Head->next == NULL && x == 1){
        delete Head;
        return NULL;
    }
    if(x==1){
        Node* ptr = Head;
        Head = Head->next;
        cout<<ptr->data<<" deleted successfully...\n";
        delete ptr;
        return Head;
    }
    Node *ptr = Head, *pre =NULL;
    int n = 1;
    while(n!=x && ptr->next!=NULL){
        pre = ptr;
        ptr=ptr->next;
        n++;
    }
    if(n!=x){
        cout<<"The given node doesnt exists...\n";
        return Head;
    }
    pre->next = ptr->next;
    cout<<ptr->data<<" deleted successfully...\n";
    delete ptr;
    return Head;
}

Node *deletePointerNodeWithoutHead(Node *curr){
    //Note that this function assumes that the node to be deleted is not the last node in the list.
    // It will not work correctly if the node to be deleted is the last node.
    if(curr==NULL || curr->next == NULL) return ; 
    Node *temp = curr->next;
    curr->data = temp->data;
    curr->next = temp->next;
    delete temp;
    return curr;
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

    // Head = deleteFirstNode(Head);
    // displayLL(Head);
    Head = deleteLastNode(Head);
    displayLL(Head);
    Head = deleteLastNode(Head);
    displayLL(Head);

    int d;
    cout<<"Enter the node to delete : ";
    cin>>d;

    Head = deleteParticularNode(Head, d);
    displayLL(Head);




    return 0;
}