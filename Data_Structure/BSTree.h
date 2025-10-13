//
// Created by shinoship on 2025/9/30.
//

#ifndef ALGORITHMS_BST_H
#define ALGORITHMS_BST_H
#include"BinaryTree.h"

//二叉搜索树的查找_迭代方式
BinaryTree* BST_Search(BinaryTree* root, int target) {
    while (root != nullptr && root->data != target) {
        if (target < root->data) {
            root = root->left;
        } else {
            root = root->rchild;
        }
    }
    return root;  // 找到返回节点，否则返回 nullptr
}

BinaryTree* BST_Insert(BinaryTree* root, int target) {
    if (root == nullptr) {
        return new BinaryTree(target);  // 创建新节点并返回
    }

    if (target == root->data) {
        return root;  // 已存在，不插入，返回原树
    }
    else if (target < root->data) {
        root->left = BST_Insert(root->left, target);  // 更新左子树
    }
    else {
        root->rchild = BST_Insert(root->rchild, target);  // 更新右子树
    }

    return root;  // 返回根节点
}
void buildBST(const vector<int>& arr) {
    BinaryTree* root = nullptr;
    for (auto i : arr) {
        root = BST_Insert(root, i);
    }
}


#endif //ALGORITHMS_BST_H