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

//随机分配主元
int randomPartition(vector<int> &A, int left, int right) {
    srand(time(0));
    int random_pivot = left + rand() % (right - left + 1);

    swap(A[right], A[random_pivot]);
    return Partition(A, left, right);
}

void random_quick_sort(vector<int> &A, int left, int right) {
    if (left < right) {
        int q = randomPartition(A, left, right);
        random_quick_sort(A, left, q - 1);
        random_quick_sort(A, q + 1, right);
    }
}

//三路快排
pair<int, int> partition3Way(vector<int>& A, int left, int right) {
    if (left >= right) return {left, right};

    int pivot = A[left];  // 选最左边为主元
    int lt = left;        // A[left .. lt-1] < pivot
    int gt = right;       // A[gt+1 .. right] > pivot
    int i = left + 1;     // 当前扫描指针

    while (i <= gt) {
        if (A[i] < pivot) {
            swap(A[lt], A[i]);
            lt++;
            i++;
        } else if (A[i] > pivot) {
            swap(A[i], A[gt]);
            gt--;
            // 注意：i 不增加，因为从右边换过来的新值还没检查
        } else {
            i++;  // A[i] == pivot，直接跳过
        }
    }

    // 此时：
    //   [left, lt-1] < pivot
    //   [lt, gt]     == pivot
    //   [gt+1, right] > pivot

    return {lt, gt};
}

void quick_sort_3way(vector<int>& A, int left, int right) {
    if (left >= right) return;

    auto [lt, gt] = partition3Way(A, left, right);

    // 只需递归排序 < pivot 和 > pivot 的部分
    quick_sort_3way(A, left, lt - 1);
    quick_sort_3way(A, gt + 1, right);
}

#endif //ALGORITHMS_QUICKSORT_H