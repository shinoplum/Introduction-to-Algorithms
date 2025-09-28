//
// Created by shinoship on 2025/9/21.
//

//平均需要N^2/4次比较和N^2/4次交换

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H
#include "Example.h"
void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        for (int j = i;j>0 && arr[j] < arr[j - 1]; j--) {
            exch(arr,j,j - 1);
        }
    }
}

#endif //ALGORITHMS_INSERTIONSORT_H