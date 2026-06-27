#include <iostream>
#include <vector>
#include <cassert>
#include "../AVL/avltree.cpp"

// Helper function to do inorder traversal and collect values
void inorder(Node* root, std::vector<int>& vals) {
    if (!root) return;
    inorder(root->left, vals);
    vals.push_back(root->data);
    inorder(root->right, vals);
}

// Helper function to check if tree is balanced (AVL property)
int checkAVL(Node* root) {
    if (!root) return 0;
    int lh = checkAVL(root->left);
    int rh = checkAVL(root->right);
    assert(std::abs(lh - rh) <= 1); // AVL property
    return 1 + std::max(lh, rh);
}

void test_insert_and_inorder() {
    Node* root = nullptr;
    std::vector<int> keys = {10, 20, 30, 50, 70, 5, 100, 95};
    for (int k : keys) root = insert(root, k);

    std::vector<int> vals;
    inorder(root, vals);

    std::vector<int> expected = {5, 10, 20, 30, 50, 70, 95, 100};
    assert(vals == expected);
}

void test_avl_balance() {
    Node* root = nullptr;
    std::vector<int> keys = {10, 20, 30, 40, 50, 25};
    for (int k : keys) root = insert(root, k);

    // Should not throw assertion
    checkAVL(root);
}

void test_no_duplicates() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 10); // duplicate

    std::vector<int> vals;
    inorder(root, vals);

    assert(vals.size() == 1 && vals[0] == 10);
}

int main() {
    test_insert_and_inorder();
    test_avl_balance();
    test_no_duplicates();
    std::cout << "All AVL tree tests passed!" << std::endl;
    return 0;
}