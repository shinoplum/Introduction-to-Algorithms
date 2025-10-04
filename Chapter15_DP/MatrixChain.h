//
// Created by shinoship on 2025/10/4.
//

#ifndef ALGORITHMS_MATRIXCHAIN_H
#define ALGORITHMS_MATRIXCHAIN_H
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1; // 矩阵个数
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // len 是链的长度（从 2 到 n）
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n];
}


#endif //ALGORITHMS_MATRIXCHAIN_H