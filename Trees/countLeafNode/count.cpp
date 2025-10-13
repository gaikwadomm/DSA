#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Class Solution
class Solution {
  public:
    // void count(Node *root, int &ans){
    //     if(!root) return;
    //     count(root->left, ans);
    //     count(root->right, ans);
    //     if(!root->left && !root->right) ans++;
    // }
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if(root==NULL) return 0;
        if(!root->left && !root->right) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
};