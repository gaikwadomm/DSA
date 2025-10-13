#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    void lv(Node *root, vector<int> &ans, int level){
        if(!root) return;
        
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        
        lv(root->left, ans, level+1);
        lv(root->right, ans, level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};
        vector<int> ans;
        lv(root, ans, 0);
        return ans;
    }
};