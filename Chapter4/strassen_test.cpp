//
// Created by shinoship on 2025/9/28.
//
#include "Strassen.h"

int main() {
    // 示例：4x4 矩阵
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };  // 单位矩阵

    cout << "Matrix A:\n";
    printMatrix(A);

    cout << "Matrix B (Identity):\n";
    printMatrix(B);

    Matrix C = strassenMultiply(A, B);

    cout << "Result A x B (should equal A):\n";
    printMatrix(C);

    return 0;
}