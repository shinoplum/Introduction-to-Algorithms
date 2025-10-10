//
// Created by shinoship on 2025/10/4.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    std::pair<int, std::string> longestPalindromeSubseqWithResult(std::string s) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // 初始化：单个字符
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // 填 DP 表
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // 回溯构造最长回文子序列
        std::string lps = buildLPS(s, dp, 0, n - 1);
        return {dp[0][n - 1], lps};
    }

private:
    std::string buildLPS(const std::string& s, const std::vector<std::vector<int>>& dp, int i, int j) {
        if (i > j) return "";
        if (i == j) return std::string(1, s[i]);

        std::string result;
        if (s[i] == s[j]) {
            // 两端字符相同，都加入结果
            result = s[i] + buildLPS(s, dp, i + 1, j - 1) + s[j];
        } else {
            // 选择更长的一边
            if (dp[i + 1][j] > dp[i][j - 1]) {
                result = buildLPS(s, dp, i + 1, j);
            } else {
                result = buildLPS(s, dp, i, j - 1);
            }
        }
        return result;
    }
};

// 测试函数
int main() {
    Solution solution;

    auto [len1, seq1] = solution.longestPalindromeSubseqWithResult("bbbab");
    std::cout << "String: bbbab -> Length: " << len1 << ", Subsequence: " << seq1 << std::endl;

    auto [len2, seq2] = solution.longestPalindromeSubseqWithResult("cbbd");
    std::cout << "String: cbbd -> Length: " << len2 << ", Subsequence: " << seq2 << std::endl;

    auto [len3, seq3] = solution.longestPalindromeSubseqWithResult("a");
    std::cout << "String: a -> Length: " << len3 << ", Subsequence: " << seq3 << std::endl;

    auto [len4, seq4] = solution.longestPalindromeSubseqWithResult("abcdef");
    std::cout << "String: abcdef -> Length: " << len4 << ", Subsequence: " << seq4 << std::endl;

    return 0;
}
