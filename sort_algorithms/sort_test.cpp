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

int main() {
    vector<int>arr = {4,2,3,5,6,1,7,8,9};
    //selection_sort(arr);
    //insertion_sort(arr);
    // shell_sort(arr);
    // merge_sort(arr,0,8);
    quick_sort(arr, 0, arr.size() - 1);
    show2(arr);
}
