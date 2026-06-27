#include<bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++

class Solution {
  public:
    class Node{
        public:
            int data;
            Node *left;
            Node *right;
        
            Node(int x) {
                data = x;
                left = NULL;
                right = NULL;
            }  
    };
    
    int find(int arr[], int target, int start, int end){
        for(int i=start;i<=end;i++){
            if(arr[i]==target) return i;
        }
        return -1;
    }
    
    Node *post_in(int in[], int post[], int index, int inStart, int inEnd) {
        if(inStart>inEnd) return NULL;

        Node *root = new Node(post[index]);
        int pos = find(in, post[index], inStart, inEnd);
        if(pos==-1) return NULL;
        root->left = post_in(in, post, index-(inEnd-pos)-1, inStart, pos-1);
        root->right = post_in(in, post, index-1, pos+1, inEnd);

        return root;
    }
    Node *pre_in(int pre[], int in[], int index, int instart, int inend){

        if(instart>inend) return NULL;

        int pos = find(in, pre[index], instart, inend);
        if(pos==-1) return NULL;
        Node* root = new Node(pre[index]);
        root->left = pre_in(pre, in, index+1, instart, pos-1);
        root->right = pre_in(pre, in, index+(pos-instart)+1, pos+1, inend);

        return root;
    }
    bool check(Node *root1, Node *root2) {
        if(root1==NULL && root2==NULL) return 1;
        
        if(root1==NULL || root2==NULL) return 0;
        
        return (root1->data==root2->data) && check(root1->left, root2->left) && check(root1->right, root2->right);
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        // Your code goes here
        int n = N; 

        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[inorder[i]] = i;
        }
        Node *root1 = post_in(inorder, postorder, n-1, 0, n-1);
        Node *root2 = pre_in(preorder, inorder, 0, 0, n-1);
        
        return check(root1, root2);
    }
};