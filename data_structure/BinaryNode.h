//
// Created by shinoship on 2025/9/30.
//

#ifndef ALGORITHMS_BINARYTREE_H
#define ALGORITHMS_BINARYTREE_H
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//二叉树类实现
class BinaryNode {
    public:
    int data;
    BinaryNode* left;
    BinaryNode* right;
};

class BinaryTree {
    public:
    BinaryNode* root;

    //初始化
    BinaryTree() : root(nullptr) {}
};

// 前序遍历 - 递归
void preOrder(BinaryNode* root) {
    if (root != NULL) {
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历 - 递归
void inOrder(BinaryNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}

// 后序遍历 - 递归
void postOrder(BinaryNode* Tree) {
    if (Tree != NULL) {
        postOrder(Tree->left);
        postOrder(Tree->right);
        cout << Tree->data;
    }
}

//层次遍历
void levelOrder(BinaryNode* root) {
    if (root == nullptr) {
        cout << "树为空" << endl;
        return;
    }

    queue<BinaryNode*> q;  // 创建一个存储节点指针的队列
    q.push(root);          // 根节点入队

    while (!q.empty()) {
        BinaryNode* current = q.front();  // 取出队首节点
        q.pop();

        cout << current->data << " ";     // 访问当前节点

        // 左子节点入队
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // 右子节点入队
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}
#endif //ALGORITHMS_BINARYTREE_H