//
// Created by shinoship on 2025/9/26.
//
#include"Example.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "SelectSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"

int main() {
    vector<int>arr = {4,2,3,5,6,1,7,8,9};
    // selectSort(arr);
    // insertSort(arr);
    //  shellSort(arr);
    //  mergeSort(arr,0,8);
    // quickSort(arr, 0, arr.size() - 1);
    radixSort(arr);
    show2(arr);
}
