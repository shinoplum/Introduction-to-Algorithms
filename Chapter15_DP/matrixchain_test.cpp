//
// Created by shinoship on 2025/10/4.
//
#include <vector>
#include <climits>
#include <iostream>
#include "MatrixChain.h"
using namespace std;


// 示例
int main() {
    vector<int> p = {10, 20, 30, 40}; // 3 个矩阵
    cout << "最小乘法次数: " << matrixChainOrder(p) << endl; // 输出 18000
    return 0;
}