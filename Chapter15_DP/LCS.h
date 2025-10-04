//
// Created by shinoship on 2025/10/4.
//

#ifndef ALGORITHMS_LCS_H
#define ALGORITHMS_LCS_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class LCS {
public:
    // 方法1：返回LCS长度
    static int lcsLength(const std::string& X, const std::string& Y) {
        int m = X.length();
        int n = Y.length();

        // 创建二维DP表，dp[i][j]表示X[0..i-1]和Y[0..j-1]的LCS长度
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // 填充DP表
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    // 方法2：同时返回LCS长度和实际的LCS字符串
    static std::pair<int, std::string> lcsWithSequence(const std::string& X, const std::string& Y) {
        int m = X.length();
        int n = Y.length();

        // 创建DP表
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // 填充DP表
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 回溯构造LCS字符串
        std::string lcs = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs = X[i - 1] + lcs;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return {dp[m][n], lcs};
    }
};

#endif //ALGORITHMS_LCS_H