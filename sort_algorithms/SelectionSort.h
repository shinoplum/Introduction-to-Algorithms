//
// Created by shinoship on 2025/9/21.
//

//平均需要n^2/2次比较和n次交换

#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H
#include "Example.h"
void selection_sort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n ; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        exch(arr,i,min);
    }
}


#endif //ALGORITHMS_SELECTIONSORT_H