//
// Created by shinoship on 2025/10/10.
//

#ifndef ALGORITHMS_ACTIVITYSELECTOR_H
#define ALGORITHMS_ACTIVITYSELECTOR_H
#include <iostream>
#include <vector>
using namespace std;


// 递归活动选择函数
// s: 开始时间数组
// f: 结束时间数组
// k: 上一个被选中的活动索引
// n: 活动总数（f 的大小为 n+1，f[0] 通常设为 0 或哨兵）
vector<int> recActivitySelector(vector<int>& s,vector<int>& f,int k,int n) {
    int m = k + 1;
    // 找到第一个与活动 k 兼容的活动（即 s[m] >= f[k]）
    while (m <= n && s[m] < f[k]) {
        m++;
    }
    if (m <= n) {
        vector<int> res = recActivitySelector(s,f,m,n);
        res.insert(res.begin(),m); // 将 m 插入结果开头
        return res;
    }
    else {
        return {};
    }
}

// 贪心活动选择器（迭代版）
// 前提：活动已按结束时间 f 升序排列
// s[1..n], f[1..n]：开始和结束时间（索引从1开始）
// 返回选中的活动索引（1-based）
vector<int> greedyActivitySelector(vector<int>& s,vector<int>& f) {
    int n = s.size() - 1;// s[0] 是占位符，实际活动从1到n
    vector<int> A;

    int k = 1;
    A.push_back(k); // 第一个活动总是被选中（结束时间最早）

    for (int m = 2; m <= n; m++) {
        if (s[m] >= f[k]) {// 活动 m 与活动 k 兼容
            A.push_back(m);// 更新最近选中的活动
            k = m;
        }
    }
    return A;
}

void print(const vector<int>& res) {
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}

#endif //ALGORITHMS_ACTIVITYSELECTOR_H