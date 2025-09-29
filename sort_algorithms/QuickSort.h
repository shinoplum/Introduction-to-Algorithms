//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H
#include <vector>
using namespace std;

int Partition(vector<int> &A, int left, int right) {//left == p  right = r
    int pivot = A[right];//主元 pivot == x
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (A[j] <= pivot) {
            i = i + 1;
            swap(A[j], A[i]);
        }
    }
    swap(A[right], A[i + 1]);//主元换到中间
    return (i + 1);
};

void quick_sort(vector<int> &A, int left, int right) {
    if (left < right) {
        int q = Partition(A, left, right);
        quick_sort(A, left, q - 1);
        quick_sort(A, q + 1, right);
    }
}


#endif //ALGORITHMS_QUICKSORT_H