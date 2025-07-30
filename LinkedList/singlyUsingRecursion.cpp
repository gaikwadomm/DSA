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

Node *createLinkedList(int index, int size){
    if(index== size){
        return NULL;
    }
    int n;
    cout << "Enter value for node " << index + 1 << ": ";
    cin >> n;
    Node *newNode;
    newNode = new Node(n);
    newNode->next = createLinkedList(index+1, size);
    return newNode;
}

Node *insertBetween(int x, Node *Head){
    Node *ptr, *newNode;
    ptr=Head;
    int val;
    cout<<"Enter the Value : ";
    cin>>val;
    newNode = new Node(val);
    int n = 1;
    while(n<x){
        // cout<<n<<"\n";
        n++;
        ptr=ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
    return Head;
}

Node *insertBegining(int index, int size, Node* Head){
    if(index==size){
        return Head;
    }
    int n;
    cout << "Enter value for node " << index + 1 << ": ";
    cin >> n;
    Node *newNode = new Node(n);
    newNode->next = Head;
    return insertBegining(index + 1, size, newNode);
}

int main(){
    int size;
    cout<<"Enter the size of the Linked List : ";
    cin>>size;
    // Node *Head = createLinkedList(0, size);
    // Node *ptr = Head;
    // while(ptr){
    //     cout<<ptr->data<<"->";
    //     ptr = ptr->next;
    // }
    Node *Head = insertBegining(0, size, NULL);
    Node *ptr = Head;
    while(ptr){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout<<"\nEnter the node after which the value to insert : ";
    int n;
    cin>>n;
    Head = insertBetween(n, Head);
    ptr = Head;
    while(ptr){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}