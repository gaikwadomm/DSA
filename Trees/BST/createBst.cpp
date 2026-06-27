#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorderTraversal(Node* root){
    // Base case
    if(!root) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    int arr[] = {5, 1, 3, 7, 4, 2, 7};
    Node* root = NULL;
    for(int i = 0; i < 7; i++){
        root = insertBST(root, arr[i]);
    }
    inorderTraversal(root);
    cout << endl;
    return 0;
}