#include<iostream>
#include<vector>
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

//Extra space is created
bool Plaindrome(Node *head){
    vector<int> temp;
    Node *ptr = head;
    while(ptr){
        temp.push_back(ptr->data);
        ptr = ptr->next;
    }
    int start = 0, end = temp.size()-1;
    while(start<end){
        if(temp[start]!=temp[end]){
            return 0;
        }
    }
    return 1;
}

//No extra space created
bool plaindromeVal(Node *head){
    
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