#include<iostream>
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

Node *removeDuplicates(Node *head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* current = head->next, *prev = head;
    while(current){
        if(current->data == prev->data){
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else{
            prev = prev->next;
            current = current->next;
        }
    }
    return head;
}

//OR

Node* removeDuplicatesAnotherMethod(Node* head) {
    if(head->next==NULL) return head;

    // code here
    Node *ptr = head;
    
    while(ptr && ptr->next){
        if(ptr->data == ptr->next->data){
            Node *temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        } else{
            ptr = ptr->next;
        }
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