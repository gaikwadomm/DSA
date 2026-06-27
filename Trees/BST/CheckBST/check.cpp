#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isBSTUtil(Node* node, int minValue, int maxValue) {
    // An empty tree is a BST
    if (node == NULL) {
        return true;
    }

    // Check if the current node's data is within the valid range
    if (node->data < minValue || node->data > maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees with updated ranges
    return isBSTUtil(node->left, minValue, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, maxValue);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}