//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& A) {
    int n = A.size();
    if (n <= 1) return;

    // 步骤1：创建 n 个桶，每个桶是一个 list<float>
    vector<list<float>> buckets(n);

    // 步骤2：将元素分配到各个桶中
    for (float x : A) {
        int bucketIdx = static_cast<int>(n * x);      // 映射到 [0, n)
        bucketIdx = min(bucketIdx, n - 1);            // 防止 x=1.0 导致越界
        buckets[bucketIdx].push_back(x);
    }

    // 步骤3：对每个桶内部排序
    for (auto& bucket : buckets) {
        bucket.sort();  // list 自带 sort 成员函数（稳定且高效）
    }

    // 步骤4：合并所有桶的结果回原数组
    auto it = A.begin();
    for (const auto& bucket : buckets) {
        for (const float& x : bucket) {
            *it = x;
            ++it;
        }
    }
}

#endif //ALGORITHMS_BUCKETSORT_H