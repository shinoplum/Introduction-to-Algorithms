//
// Created by shinoship on 2025/10/13.
//
#include <iostream>
#include "BTree.h"
using namespace std;

int main() {
    BTree tree;
    std::vector<int> keys = {10, 20, 5, 6, 12, 30, 7, 17};

    for (int k : keys) {
        tree.insert(k);
    }

    // 测试搜索
    for (int k : {5, 10, 15, 30}) {
        auto node = tree.search(k);
        if (node) {
            std::cout << "Found " << k << "\n";
        } else {
            std::cout << k << " not found\n";
        }
    }

    return 0;
}