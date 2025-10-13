#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void display(Node *root) {
    if (!root) {
        cout << "-1 ";
        return;
    }

    // Simple preorder display
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

Node *Binary(){
    int x;
    cout<<"Enter Number : ";
    cin>>x;
    if(x==-1) return NULL;

    Node *temp = new Node(x);

    temp->left = Binary();
    temp->right = Binary();

    return temp;
}

int main() {
    // int x;
    // cout << "Enter root value: ";
    // cin >> x;

    // Node *root = new Node(x);
    // stack<Node *> st;
    // st.push(root);

    // while (!st.empty()) {
    //     Node *curr = st.top();
    //     int left, right;
        
    //     if(curr->left==NULL){
    //         cout << "Enter left of " << curr->data << " (-1 for none): ";
    //         cin >> left;
    //         if (left != -1 ) {
    //             curr->left = new Node(left);
    //             st.push(curr->left);
    //             continue; // go deeper (left direction)
    //         }
    //     }

    //     if(curr->right==NULL){
    //         cout << "Enter right of " << curr->data << " (-1 for none): ";
    //         cin >> right;
    //         if (right != -1) {
    //             curr->right = new Node(right);
    //             st.push(curr->right);
    //             continue; // go deeper (right direction)
    //         }
    //     }

    //     // Both are -1, move back
    //     st.pop();
    // }

    Node *root = Binary();

    cout << "\nTree in preorder: ";
    display(root);
    cout << endl;
}
