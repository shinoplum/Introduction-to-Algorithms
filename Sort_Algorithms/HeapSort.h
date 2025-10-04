//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_HEAPSORT_H
#define ALGORITHMS_HEAPSORT_H
#include "../Data_Structure/MaxHeap.h"

void heapSort(vector<int> &A) {
    MaxHeap::buildMaxHeap(A);
    int heap_size = A.size();
    int n = A.size();

    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        heap_size = heap_size - 1;
        MaxHeap::maxHeapify_rec(A, heap_size,0);
    }
}


#endif //ALGORITHMS_HEAPSORT_H