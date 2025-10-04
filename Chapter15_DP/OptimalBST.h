//
// Created by shinoship on 2025/10/4.
//

#ifndef ALGORITHMS_OPTIMALBST_H
#define ALGORITHMS_OPTIMALBST_H
#include <bits/stdc++.h>
using namespace std;

class OptimalBST {
private:
    std::vector<double> p;  // 键的搜索概率 p[1..n]
    std::vector<double> q;  // 虚拟键的搜索概率 q[0..n]
    int n;                  // 键的数量

    // DP表
    std::vector<std::vector<double>> e;    // e[i][j] = 子树包含键ki..kj的期望搜索代价
    std::vector<std::vector<double>> w;    // w[i][j] = 子树包含键ki..kj的总概率
    std::vector<std::vector<int>> root;    // root[i][j] = 子树包含键ki..kj的根节点

public:
    // 构造函数
    OptimalBST(const std::vector<double>& probabilities,
               const std::vector<double>& dummy_probabilities) {
        // probabilities: p[1..n] (索引0对应p1)
        // dummy_probabilities: q[0..n] (索引0对应q0)
        n = probabilities.size();
        p.resize(n + 1);
        q.resize(n + 1);

        // 复制概率值，使用1-based索引
        for (int i = 1; i <= n; i++) {
            p[i] = probabilities[i - 1];
        }
        for (int i = 0; i <= n; i++) {
            q[i] = dummy_probabilities[i];
        }

        // 初始化DP表
        e.resize(n + 2, std::vector<double>(n + 2, 0.0));
        w.resize(n + 2, std::vector<double>(n + 2, 0.0));
        root.resize(n + 2, std::vector<int>(n + 2, 0));
    }

    // 计算最优二叉搜索树
    void computeOptimalBST() {
        // 初始化：单个虚拟键的情况
        for (int i = 1; i <= n + 1; i++) {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i - 1];
        }

        // l = 子树中键的数量
        for (int l = 1; l <= n; l++) {
            // i = 子树的起始位置
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;  // 子树的结束位置

                e[i][j] = std::numeric_limits<double>::max();
                w[i][j] = w[i][j - 1] + p[j] + q[j];

                // 尝试每个可能的根节点r
                for (int r = i; r <= j; r++) {
                    double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (t < e[i][j]) {
                        e[i][j] = t;
                        root[i][j] = r;
                    }
                }
            }
        }
    }

    // 获取最小期望搜索代价
    double getMinCost() const {
        return e[1][n];
    }






    // 打印DP表（用于调试）
    void printTables() const {
        std::cout << std::fixed << std::setprecision(3);

        std::cout << "\nE table (expected cost):\n";
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 0; j <= n; j++) {
                if (j >= i - 1) {
                    std::cout << std::setw(8) << e[i][j];
                } else {
                    std::cout << std::setw(8) << " ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "\nW table (total weight):\n";
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 0; j <= n; j++) {
                if (j >= i - 1) {
                    std::cout << std::setw(8) << w[i][j];
                } else {
                    std::cout << std::setw(8) << " ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "\nRoot table:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j >= i) {
                    std::cout << std::setw(8) << root[i][j];
                } else {
                    std::cout << std::setw(8) << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    // 构建并打印最优二叉搜索树
    void printOptimalBST() const {
        std::cout << "\nOptimal BST structure:\n";
        if (n > 0) {
            printSubtree(1, n, 0, true);
        }
    }

private:
    void printSubtree(int i, int j, int depth, bool isRoot) const {
        if (i > j) {
            // 打印虚拟键
            for (int k = 0; k < depth; k++) {
                std::cout << "  ";
            }
            std::cout << "d" << j << " (q" << j << ")" << std::endl;
            return;
        }

        int r = root[i][j];

        // 打印当前根节点
        for (int k = 0; k < depth; k++) {
            std::cout << "  ";
        }
        if (isRoot) {
            std::cout << "k" << r << " (p" << r << ") [ROOT]" << std::endl;
        } else {
            std::cout << "k" << r << " (p" << r << ")" << std::endl;
        }

        // 递归打印左子树
        if (i <= r - 1) {
            for (int k = 0; k < depth + 1; k++) {
                std::cout << "  ";
            }
            std::cout << "Left: ";
            printSubtree(i, r - 1, depth + 1, false);
        } else {
            for (int k = 0; k < depth + 1; k++) {
                std::cout << "  ";
            }
            std::cout << "Left: d" << r - 1 << " (q" << (r - 1) << ")" << std::endl;
        }

        // 递归打印右子树
        if (r + 1 <= j) {
            for (int k = 0; k < depth + 1; k++) {
                std::cout << "  ";
            }
            std::cout << "Right: ";
            printSubtree(r + 1, j, depth + 1, false);
        } else {
            for (int k = 0; k < depth + 1; k++) {
                std::cout << "  ";
            }
            std::cout << "Right: d" << r << " (q" << r << ")" << std::endl;
        }
    }
};

#endif //ALGORITHMS_OPTIMALBST_H