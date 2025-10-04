//
// Created by shinoship on 2025/10/4.
//
#include "LCS.h"
#include <bits/stdc++.h>

// 测试函数
int main() {
    std::string X = "ABCDGH";
    std::string Y = "AEDFHR";

    // 测试基本LCS长度
    int length = LCS::lcsLength(X, Y);
    std::cout << "LCS Length: " << length << std::endl;

    // 测试获取LCS字符串
    auto result = LCS::lcsWithSequence(X, Y);
    std::cout << "LCS Length: " << result.first << std::endl;
    std::cout << "LCS Sequence: " << result.second << std::endl;
}