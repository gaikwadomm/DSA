#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data, height;
    Node* left, *right;
    
    Node(int val){
        data = val;
        height = 1;
        left = right = NULL;
    }
};
class Solution {
  public:
    int getHeight(Node* root){
        return root ? root->height : 0;
    }

    int getBalance(Node* root){
        return root ? getHeight(root->left) - getHeight(root->right) : 0;
    }

    // RIGHT ROTATION: y is root, x = y->left
    Node* rightRotation(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        // New root
        return x;
    }

    // LEFT ROTATION: x is root, y = x->right
    Node* leftRotation(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        // New root
        return y;
    }

    Node* insertToAVL(Node* root, int key){
        // 1. Normal BST insertion
        if(!root) return new Node(key);

        if(key < root->data)
            root->left = insertToAVL(root->left, key);
        else if(key > root->data)
            root->right = insertToAVL(root->right, key);
        else
            return root; // duplicates not allowed

        // 2. Update height of this ancestor node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // 3. Get the balance factor
        int balance = getBalance(root);

        // 4. If unbalanced, there are 4 cases

        // Left Left Case
        if(balance > 1 && key < root->left->data)
            return rightRotation(root);

        // Right Right Case
        if(balance < -1 && key > root->right->data)
            return leftRotation(root);

        // Left Right Case
        if(balance > 1 && key > root->left->data){
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        // Right Left Case
        if(balance < -1 && key < root->right->data){
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }

        // Balanced
        return root;
    }
};
