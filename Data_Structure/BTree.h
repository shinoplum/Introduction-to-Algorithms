//
// Created by shinoship on 2025/10/13.
//

#ifndef ALGORITHMS_BTREE_H
#define ALGORITHMS_BTREE_H

#include <iostream>
#include <vector>

const int T = 3; // 最小度数（minimum degree），即每个节点（除根）至少有 T-1 个关键字，至多 2T-1 个

struct BTreeNode {
    std::vector<int> keys;                // 关键字
    std::vector<BTreeNode*> children;     // 子节点指针
    bool isLeaf;

    BTreeNode(bool leaf) : isLeaf(leaf) {}
};

class BTree {
public:
    BTreeNode* root;

    BTree() : root(nullptr) {}

    // 搜索函数：对外接口
    BTreeNode* search(int key) {
        return (root == nullptr) ? nullptr : search(root, key);
    }

    void insert(int key) {
        //
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        }
        else {
            //
            if (root->keys.size() == 2 * T - 1) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0);
                root = newRoot;
            }
            insterNonFull(root, key);
        }
    }

    void remove(int key) {
        if (!root) return;
        remove(root, key);
        // 如果根变为空且不是叶子，更新根
        if (root->keys.empty() && !root->isLeaf) {
            BTreeNode* oldRoot = root;
            root = root->children[0];
            delete oldRoot;
        }
    }

private:
    // 递归搜索函数
    BTreeNode* search(BTreeNode* node, int key) {
        int i = 0;
        // 找到第一个 >= key 的位置
        while (i < node->keys.size() && key > node->keys[i]) {
            i++;
        }
        // 如果找到了 key
        if (i < node->keys.size() && key == node->keys[i]) {
            return node;
        }
        // 如果是叶子节点，说明 key 不存在
        if (node->isLeaf) {
            return nullptr;
        }

        // 否则递归搜索对应的子树
        return search(node->children[i], key);
    }

    void splitChild(BTreeNode* x, int i) {
        BTreeNode* y = x->children[i];// y 是要分裂的满子节点
        BTreeNode* z = new BTreeNode(y->isLeaf);// 创建新节点 z，保存 y 的后半部分
        // z 将获得 y 的后 T-1 个关键字（即从 T 到 2T-2）
        // y 保留前 T-1 个关键字（0 到 T-2）
        // y 的第 T-1 个关键字（索引为 T-1）是中间关键字，将被提升到 x

        // 1. 将 y 的后 T-1 个关键字复制到 z
        for (int j = 0; j < T - 1; j++) {
            z->keys.push_back(y->keys[T + j]);
        }
        // 2. 如果 y 不是叶子，还要复制对应的子节点指针
        if (!y->isLeaf) {
            for (int j = 0; j < T; j++) {
                z->children.push_back(y->children[T + j]);
            }
        }
        // 3. 缩短 y：只保留前 T-1 个关键字和子节点
        y->keys.resize(T - 1);
        if (!y->isLeaf) {
            y->children.resize(T);
        }
        // 4. 在 x 中为 z 创建位置：将 x->children[i+1 ...] 向右移动
        x->children.insert(x->children.begin() + i + 1, z);
        // 5. 将 y 的中间关键字（原 y->keys[T-1]）提升到 x
        x->keys.insert(x->keys.begin() + i, y->keys[T - 1]);

        // 注意：y->keys[T-1] 未被复制到 z，也未保留在 y 中（已被 resize 移除）
    }

    // 插入非满节点（用于递归插入）
    void insterNonFull(BTreeNode* node, int key) {
        int i = node->keys.size() - 1;
        // 在叶子节点中插入
        if (node->isLeaf) {
            node->keys.push_back(0);// 占位
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        }else {
            // 找到应该插入的子树
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;
            // 如果子节点满了，先分裂
            if (node->children[i]->keys.size() == 2 * T - 1) {
                splitChild(node, i);
                // 分裂后，x 中新增了一个关键字，判断应进入哪个子树
                if ( key > node->keys[i] ) {
                    i++;
                }
            }
            insterNonFull(node->children[i], key);
        }
    }





    void remove(BTreeNode* node, int key) {
        int idx = 0;
        while (idx < node->keys.size() && key > node->keys[idx])
            idx++;

        // 情况 1：key 在当前节点
        if (idx < node->keys.size() && key == node->keys[idx]) {
            if (node->isLeaf) {
                removeFromLeaf(node, idx);
            } else {
                removeFromNonLeaf(node, idx);
            }
        } else {
            // 情况 2：key 不在当前节点
            if (node->isLeaf) {
                // 未找到
                return;
            }

            bool last = (idx == node->keys.size());
            if (node->children[idx]->keys.size() < T) {
                fill(node, idx);
            }

            // 递归删除
            if (last && idx > node->keys.size()) {
                remove(node->children[idx - 1], key);
            } else {
                remove(node->children[idx], key);
            }
        }
    }

    void removeFromLeaf(BTreeNode* node, int idx) {
        node->keys.erase(node->keys.begin() + idx);
    }

    void removeFromNonLeaf(BTreeNode* node, int idx) {
        int k = node->keys[idx];

        // 情况 1：左子树关键字数 >= T
        if (node->children[idx]->keys.size() >= T) {
            int pred = getPred(node, idx);
            node->keys[idx] = pred;
            remove(node->children[idx], pred);
        }
        // 情况 2：右子树关键字数 >= T
        else if (node->children[idx + 1]->keys.size() >= T) {
            int succ = getSucc(node, idx);
            node->keys[idx] = succ;
            remove(node->children[idx + 1], succ);
        }
        // 情况 3：左右子树都只有 T-1 个关键字 → 合并
        else {
            merge(node, idx);
            remove(node->children[idx], k);
        }
    }

    int getPred(BTreeNode* node, int idx) {
        BTreeNode* cur = node->children[idx];
        while (!cur->isLeaf) {
            cur = cur->children.back();
        }
        return cur->keys.back();
    }

    int getSucc(BTreeNode* node, int idx) {
        BTreeNode* cur = node->children[idx + 1];
        while (!cur->isLeaf) {
            cur = cur->children[0];
        }
        return cur->keys[0];
    }

    void fill(BTreeNode* node, int idx) {
        // 尝试从左兄弟借
        if (idx != 0 && node->children[idx - 1]->keys.size() >= T) {
            borrowFromPrev(node, idx);
        }
        // 尝试从右兄弟借
        else if (idx != node->keys.size() && node->children[idx + 1]->keys.size() >= T) {
            borrowFromNext(node, idx);
        }
        // 合并
        else {
            if (idx != node->keys.size()) {
                merge(node, idx);
            } else {
                merge(node, idx - 1);
            }
        }
    }

    void borrowFromPrev(BTreeNode* node, int idx) {
        BTreeNode* child = node->children[idx];
        BTreeNode* sibling = node->children[idx - 1];

        // 右移 child 的所有关键字和子节点
        child->keys.insert(child->keys.begin(), node->keys[idx - 1]);
        if (!child->isLeaf) {
            child->children.insert(child->children.begin(), sibling->children.back());
            sibling->children.pop_back();
        }

        // 更新父节点关键字
        node->keys[idx - 1] = sibling->keys.back();
        sibling->keys.pop_back();
    }

    void borrowFromNext(BTreeNode* node, int idx) {
        BTreeNode* child = node->children[idx];
        BTreeNode* sibling = node->children[idx + 1];

        // 将父节点关键字加入 child 末尾
        child->keys.push_back(node->keys[idx]);
        if (!child->isLeaf) {
            child->children.push_back(sibling->children[0]);
            sibling->children.erase(sibling->children.begin());
        }

        // 更新父节点关键字
        node->keys[idx] = sibling->keys[0];
        sibling->keys.erase(sibling->keys.begin());
    }

    void merge(BTreeNode* node, int idx) {
        BTreeNode* child = node->children[idx];
        BTreeNode* sibling = node->children[idx + 1];

        // 将父节点关键字插入 child 末尾
        child->keys.push_back(node->keys[idx]);
        // 将 sibling 的所有关键字和子节点合并到 child
        child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
        if (!child->isLeaf) {
            child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
        }

        // 从父节点删除关键字和 sibling 指针
        node->keys.erase(node->keys.begin() + idx);
        node->children.erase(node->children.begin() + idx + 1);

        delete sibling;
    }
};

#endif //ALGORITHMS_BTREE_H