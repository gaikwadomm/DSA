#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    // void sum(Node *root, int &ans){
    //     if(!root) return;
    //     ans+=root->data;
    //     sum(root->left, ans);
    //     sum(root->right, ans);
    // }
    int sumBT(Node* root) {
        if(!root) return 0;
        return root->data + sumBT(root->left) + sumBT(root->right);
    }
};