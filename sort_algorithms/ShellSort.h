//
// Created by shinoship on 2025/9/21.
//

//平均比较次数为N^1.5

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H
#include "Example.h"
void shell_sort(vector<int> &arr) {
    int n = arr.size();
    int h = 1;
    while (h < n / 3) { h = 3 *h + 1; }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
                exch(arr, j, j - h);
            }
        }
        h = h / 3;
    }
}
#endif //ALGORITHMS_SHELLSORT_H