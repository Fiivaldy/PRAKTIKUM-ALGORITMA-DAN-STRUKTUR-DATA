#include <iostream>
#include <vector>
#include <string>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil || node->isNil) {
        return;
    }

    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil || node->isNil) {
        return;
    }

    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil || node->isNil) {
        return;
    }

    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printResult(const string& label, const vector<int>& result) {
    cout << "[" << label << "] :";

    for (int value : result) {
        cout << " " << value;
    }

    cout << endl;
}

int main() {
    RedBlackTree tree;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;

        if (!tree.contains(value)) {
            tree.insert(value);
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;

        if (tree.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        if (query == "PREORDER") {
            vector<int> result;
            preorder(tree.root(), tree.nil(), result);
            printResult("Preorder", result);
        } 
        else if (query == "INORDER") {
            vector<int> result;
            inorder(tree.root(), tree.nil(), result);
            printResult("Inorder", result);
        } 
        else if (query == "POSTORDER") {
            vector<int> result;
            postorder(tree.root(), tree.nil(), result);
            printResult("Postorder", result);
        } 
        else if (query == "ALL") {
            vector<int> pre, in, post;

            preorder(tree.root(), tree.nil(), pre);
            inorder(tree.root(), tree.nil(), in);
            postorder(tree.root(), tree.nil(), post);

            printResult("Preorder", pre);
            printResult("Inorder", in);
            printResult("Postorder", post);
        }
    }

    return 0;
}