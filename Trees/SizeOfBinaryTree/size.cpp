#include<bits/stdc++.h>
using namespace std;

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

class Solution {
  public:
    int count(Node *node){
        if(!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
    
    int getSize(Node* node) {
        // code here
        return count(node);
    }
};