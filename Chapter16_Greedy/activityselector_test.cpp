//
// Created by shinoship on 2025/10/10.
//
#include<iostream>
#include"ActivitySelector.h"
using namespace std;

int main() {
    // 示例：活动 1 到 n（索引从 1 开始）
    // 添加一个虚拟的活动 0（哨兵），f[0] = 0
    vector<int> s = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}; // 开始时间（s[0] 未使用或设为0）
    vector<int> f = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16}; // 结束时间（已排序）

    int n = s.size() - 1; // 实际活动数量（忽略索引0）

    // 确保 f 是升序（题目通常假设已排序）
    // 如果未排序，需先按 f 排序并同步调整 s
    vector<int> res = recActivitySelector(s,f,0,n);
    vector<int> res2 = greedyActivitySelector(s,f);
    print(res2);
    print(res);
    return 0;
}