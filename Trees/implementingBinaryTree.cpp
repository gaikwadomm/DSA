#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void display(Node *root){
    if(!root){ 
        cout<<"No node in tree!";
        return;
    }
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        q.pop();
    }
    cout<<endl;
}

int main(){
    int x, left, right;
    queue<Node *> q;
    cout<<"Enter the Node : ";
    cin>>x;
    
    Node *root = new Node(x);
    q.push(root);

    while(!q.empty()){
        cout<<"Enter the Node : ";
        cin>>left;

        if(left!=-1){
            Node *temp = q.front();
            temp->left = new Node(left);
            q.push(temp->left);
        }

        cout<<"Enter the Node : ";
        cin>>right;

        if(right!=-1){
            Node *temp = q.front();
            temp->right = new Node(right);
            q.push(temp->right);
        }

        q.pop();
    }

    display(root);
    
}