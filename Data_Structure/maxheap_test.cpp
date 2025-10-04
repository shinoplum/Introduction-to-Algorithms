//
// Created by shinoship on 2025/9/28.
//

#include<vector>
#include<iostream>
#include "MaxHeap.h"
#include "../Sort_Algorithms/HeapSort.h"
using namespace std;

int main() {
    //maxHeapify_test
    vector<int> A = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};  // 几乎是堆，但 A[1]=4 不满足
    int heap_size = A.size();

    cout << "Before MAX-HEAPIFY at index 1:\n";
    for (int x : A) cout << x << " ";
    cout << endl;

    // 假设我们要修复以索引 1 为根的子树
    MaxHeap::maxHeapify_rec(A,heap_size,1);

    cout << "After MAX-HEAPIFY:\n";
    for (int x : A) cout << x << " ";
    cout << endl;


    //buildMaxHeap_test
    vector<int> B = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    cout << "Original array: ";
    for (int x : B) cout << x << " ";
    cout << endl;

    MaxHeap::buildMaxHeap(B);

    cout << "After buildMaxHeap: ";
    for (int x : B) cout << x << " ";
    cout << endl;

    //HeapSort_test
    vector<int> C = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    cout << "Original array: ";
    for (int x : C) cout << x << " ";
    cout << endl;

    heapSort(C);

    cout << "After buildMaxHeap: ";
    for (int x : C) cout << x << " ";
    cout << endl;


    return 0;
}