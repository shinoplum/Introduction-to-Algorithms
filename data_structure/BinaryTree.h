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
class BinaryTree {
    public:
    int data;
    BinaryTree* lchild;
    BinaryTree* rchild;
};

// 前序遍历 - 递归
void preOrder(BinaryTree* Tree) {
    if (Tree != NULL) {
        cout << Tree->data;
        preOrder(Tree->lchild);
        preOrder(Tree->rchild);
    }
}

// 中序遍历 - 递归
void inOrder(BinaryTree* Tree) {
    if (Tree != NULL) {
        inOrder(Tree->lchild);
        cout << Tree->data;
        inOrder(Tree->rchild);
    }
}

// 后序遍历 - 递归
void postOrder(BinaryTree* Tree) {
    if (Tree != NULL) {
        postOrder(Tree->lchild);
        postOrder(Tree->rchild);
        cout << Tree->data;
    }
}

//层次遍历
void levelOrder(BinaryTree* root) {
    if (root == nullptr) {
        cout << "树为空" << endl;
        return;
    }

    queue<BinaryTree*> q;  // 创建一个存储节点指针的队列
    q.push(root);          // 根节点入队

    while (!q.empty()) {
        BinaryTree* current = q.front();  // 取出队首节点
        q.pop();

        cout << current->data << " ";     // 访问当前节点

        // 左子节点入队
        if (current->lchild != nullptr) {
            q.push(current->lchild);
        }

        // 右子节点入队
        if (current->rchild != nullptr) {
            q.push(current->rchild);
        }
    }
    cout << endl;
}
#endif //ALGORITHMS_BINARYTREE_H