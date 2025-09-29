//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_RADIXSORT_H
#define ALGORITHMS_RADIXSORT_H
#include <vector>
#include <algorithm>
using namespace std;


// 辅助函数：按指定位（exp 表示 1, 10, 100...）进行计数排序
void countingSortByDigit(vector<int>& A, int exp) {
    int n = A.size();
    vector<int> B(n);           // 临时输出数组
    vector<int> C(10, 0);       // 计数数组（0~9）

    // 第一步：统计当前位上每个数字出现的次数
    for (int i = 0; i < n; i++) {
        int digit = (A[i] / exp) % 10;
        C[digit]++;
    }

    // 第二步：累积计数（C[i] 表示 <= i 的数字有多少个）
    for (int j = 1; j < 10; j++) {
        C[j] += C[j - 1];
    }

    // 第三步：从后往前填充 B，保证稳定性
    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        B[C[digit] - 1] = A[i];  // 注意减1：下标从0开始
        C[digit]--;
    }

    // 第四步：复制回原数组
    A = B;
}

// 基于计数排序的基数排序（仅适用于非负整数）
void radixSort(vector<int>& A) {
    if (A.empty()) return;

    // 步骤1：找出最大值，确定最大位数
    int maxVal = *max_element(A.begin(), A.end());//<algorithm>中函数

    // 步骤2：从个位开始，对每一位进行计数排序
    // exp = 1, 10, 100, ..., 直到超过 maxVal
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(A, exp);
    }
}




#endif //ALGORITHMS_RADIXSORT_H