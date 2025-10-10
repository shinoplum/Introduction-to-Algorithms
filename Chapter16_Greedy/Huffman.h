//
// Created by shinoship on 2025/10/10.
//

#ifndef ALGORITHMS_HUFFMAN_H
#define ALGORITHMS_HUFFMAN_H
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// CLRS 风格的 Huffman 树节点
struct Node {
    char ch;        // 仅叶子节点使用
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(int f) : ch('\0'), freq(f), left(nullptr), right(nullptr) {} // 内部节点
};

// 自定义比较器：最小堆（频率小的优先）
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // 注意：priority_queue 是最大堆，所以用 > 实现最小堆
    }
};

// CLRS: HUFFMAN(C)
// 输入：字符及其频率的映射
// 输出：Huffman 树的根节点
Node* Huffman(const unordered_map<char, int>& freqMap) {
    // 步骤 1: 初始化最小优先队列 Q
    priority_queue<Node*, vector<Node*>, Compare> Q;

    // 将每个字符作为叶子节点加入 Q
    for (const auto& p : freqMap) {
        Q.push(new Node(p.first, p.second));
    }

    // 步骤 2: 合并 n-1 次
    int n = freqMap.size();
    for (int i = 1; i <= n - 1; ++i) {
        Node* z = new Node(0); // 新内部节点
        z->left = Q.top(); Q.pop();
        z->right = Q.top(); Q.pop();
        z->freq = z->left->freq + z->right->freq;
        Q.push(z);
    }

    // 步骤 3: 返回根
    return Q.top();
}

#endif //ALGORITHMS_HUFFMAN_H