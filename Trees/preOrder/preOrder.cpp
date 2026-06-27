#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        if(!root) return{};
        vector<int> ans;

        while(root){
            
            if(!root->left){
                ans.push_back(root->data);
                root=root->right;
            }
            else{
                Node *temp = root->left;
                while(temp){
                    if(temp->right == root->right){
                        temp->right=NULL;
                        root = root->right;
                        break;
                    }
                    if(temp->right==NULL){
                        temp->right = root->right;
                        ans.push_back(root->data);
                        root = root->left;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }

        return ans;
    }
};