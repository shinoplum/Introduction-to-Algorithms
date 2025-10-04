//
// Created by shinoship on 2025/9/30.
//

#ifndef ALGORITHMS_RBT_H
#define ALGORITHMS_RBT_H

#include <iostream>
using namespace std;

// 颜色枚举
enum Color {
    RED,
    BLACK
};

// 红黑树节点
class RBNode {
public:
    int data;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int value) : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// 红黑树类
class RedBlackTree {
private:
    RBNode* root;

    // 左旋函数
    void leftRotate(RBNode* x) {
        if (x == nullptr || x->right == nullptr) return;

        RBNode* y = x->right;           // y 是 x 的右孩子

        x->right = y->left;             // 1. y 的左子树 β 变成 x 的右子树
        if (y->left != nullptr) {
            y->left->parent = x;
        }

        y->parent = x->parent;          // 2. y 接到 x 的父节点上
        if (x->parent == nullptr) {
            root = y;                   // x 是根，所以 y 成为新根
        }
        else if (x == x->parent->left) {
            x->parent->left = y;        // y 接到左边
        }
        else {
            x->parent->right = y;       // y 接到右边
        }

        y->left = x;                    // 3. x 成为 y 的左孩子
        x->parent = y;
    }

    void rightRotate(RBNode* y) {
        if (y == nullptr || y->left == nullptr) return;

        RBNode* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }

        x->parent = y->parent;
        if (y->parent == nullptr) {
            root = x;
        }
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    void RB_Insert_Fixup(RBNode* z) {
        while (z->parent->color == RED) {
            // 父节点是祖父的左孩子
            if (z->parent ==z->parent->parent->left) {
                RBNode* y = z->parent->right;// 叔叔节点

                if (y->color == RED) {
                    // Case 1: 叔叔是红色 → 变色，向上调整
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;// 将 z 上移两层
                }

                // Case 2 & 3: 叔叔是黑色或不存在
                else if (z == z->parent->right) {
                    // Case 2: 当前节点是右孩子 → 左旋转为 Case 3
                    z = z->parent;
                    leftRotate(z);
                }
                // Case 3: 统一处理：染色 + 右旋
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }

            // 对称情况：父节点是祖父的右孩子
            else {

            }
        }
        // 最终确保根节点为黑色
        root->color = BLACK;
    }

    void RB_Insert(int value) {
        RBNode* newNode = new RBNode(value);
        RBNode* parent = nullptr;
        RBNode* current = root;

        // 1. 查找插入位置
        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        // 2. 连接到父节点
        if (parent == nullptr) {
            root = newNode;// 树为空，新节点为根
        }
        else if (value < parent->data) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->color = RED;

        RB_Insert_Fixup();
    }

public:
    // 构造函数：初始化 root 为 nullptr
    RedBlackTree() : root(nullptr) {}
};

#endif //ALGORITHMS_RBT_H