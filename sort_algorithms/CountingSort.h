//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_COUNTINGSORT_H
#define ALGORITHMS_COUNTINGSORT_H
#include <vector>
using namespace std;

void countingSort(vector<int>& A,vector<int>& B,int k) {
    vector<int> C(k, 0);
    int Asize = A.size();

    // 第一步：统计每个元素出现的次数
    for (int i = 0; i < Asize; i++) {
        C[A[i]] = C[A[i]] + 1;
    }

    // 第二步：计算累积计数（C[i] 表示小于等于 i 的元素个数）
    for (int j = 1; j < k; j++) {
        C[j] = C[j] + C[j - 1];
    }

    // 第三步：从后往前遍历 A，将元素放到输出数组 B 的正确位置
    // 保证稳定性
    for (int i = Asize - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];// 因为下标从0开始，所以减1
        C[A[i]] = C[A[i]] - 1;// 更新计数
    }
};

#endif //ALGORITHMS_COUNTINGSORT_H