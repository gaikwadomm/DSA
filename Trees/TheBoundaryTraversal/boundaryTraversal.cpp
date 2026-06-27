#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void boundLeft(Node *root, vector<int>& ans){
        if(!root || (!root->left && !root->right)) return;
        
        ans.push_back(root->data);
        if(root->left) boundLeft(root->left, ans);
        else boundLeft(root->right, ans);
    }
    
    void boundLeaf(Node *root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) ans.push_back(root->data);
        boundLeaf(root->left, ans);
        boundLeaf(root->right, ans);
    }
    
    void boundRight(Node *root, vector<int>& ans){
        if(!root || (!root->left && !root->right)) return;

        if(root->right) boundRight(root->right, ans);
        else boundRight(root->left, ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);

        boundLeft(root->left, ans);

        boundLeaf(root->left, ans);
        boundLeaf(root->right, ans);
        
        vector<int> rightBound;
        boundRight(root->right, rightBound);
        for(int i=0; i<rightBound.size(); i++){
            ans.push_back(rightBound[i]);
        }

        return ans;
    }
};