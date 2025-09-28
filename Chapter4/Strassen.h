//
// Created by shinoship on 2025/9/28.
//

#ifndef ALGORITHMS_STRASSEN_H
#define ALGORITHMS_STRASSEN_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 使用 double 类型，也可以换成 int 或 template
using Matrix = vector<vector<double>>;

// 打印矩阵（调试用）
void printMatrix(const Matrix& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout.width(6);  // 设置输出宽度
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 矩阵加法：A + B
Matrix matrixAdd(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// 矩阵减法：A - B
Matrix matrixSubtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// 基础矩阵乘法（当 n 很小时回退到普通乘法）
Matrix matrixMultiplyBasic(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Strassen 算法主函数（要求 n 是 2 的幂）
Matrix strassenMultiply(const Matrix& A, const Matrix& B, int base_case = 64) {
    int n = A.size();

    // 边界条件：小矩阵使用朴素乘法
    if (n <= base_case) {
        return matrixMultiplyBasic(A, B);
    }

    // 创建子矩阵（每个大小为 n/2）
    int half = n / 2;
    Matrix A11(half, vector<double>(half)), A12(half, vector<double>(half)),
           A21(half, vector<double>(half)), A22(half, vector<double>(half));
    Matrix B11(half, vector<double>(half)), B12(half, vector<double>(half)),
           B21(half, vector<double>(half)), B22(half, vector<double>(half));

    // 分割矩阵 A 和 B
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // 步骤 1: 计算 10 个辅助和/差矩阵（减少乘法次数）
    Matrix S1 = matrixSubtract(B12, B22);
    Matrix S2 = matrixAdd(A11, A12);
    Matrix S3 = matrixAdd(A21, A22);
    Matrix S4 = matrixSubtract(B21, B11);
    Matrix S5 = matrixAdd(A11, A22);
    Matrix S6 = matrixAdd(B11, B22);
    Matrix S7 = matrixSubtract(A12, A22);
    Matrix S8 = matrixAdd(B21, B22);
    Matrix S9 = matrixSubtract(A11, A21);
    Matrix S10 = matrixAdd(B11, B12);

    // 步骤 2: 递归计算 7 个乘积 M1 ~ M7
    Matrix M1 = strassenMultiply(S5, S6, base_case);         // (A11+A22)(B11+B22)
    Matrix M2 = strassenMultiply(S3, B11, base_case);        // (A21+A22)B11
    Matrix M3 = strassenMultiply(A11, S1, base_case);        // A11(B12-B22)
    Matrix M4 = strassenMultiply(A22, S4, base_case);        // A22(B21-B11)
    Matrix M5 = strassenMultiply(S2, B22, base_case);        // (A11+A12)B22
    Matrix M6 = strassenMultiply(S9, S8, base_case);         // (A21-A11)(B21+B22)
    Matrix M7 = strassenMultiply(S7, S10, base_case);        // (A12-A22)(B11+B12)

    // 步骤 3: 组合出结果子矩阵 C11, C12, C21, C22
    Matrix C11 = matrixAdd(matrixSubtract(matrixAdd(M1, M4), M5), M7);
    Matrix C12 = matrixAdd(M3, M5);
    Matrix C21 = matrixAdd(M2, M4);
    Matrix C22 = matrixAdd(matrixSubtract(M1, M2), matrixAdd(M3, M6));

    // 合并为完整矩阵
    Matrix C(n, vector<double>(n));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}

#endif //ALGORITHMS_STRASSEN_H