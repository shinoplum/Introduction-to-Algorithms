//
// Created by shinoship on 2025/9/23.
//

//对于长度为n的任意数组，自顶向下的归并排序需要1/2*N*lgN至N*lgN次比较

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H
#include "Example.h"

void merge(vector<int> &A,int low,int mid,int high) {
    int n1 = mid - low + 1;//左数组的长度
    int n2 = high - mid;//右数组的长度

    vector<int> L(n1);
    vector<int> R(n2);

    //复制数组
    for (int i = 0; i < n1; i++) {
        L[i] = A[low + i];
        //std::cout<<L[i]<<" ";
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
        //std::cout<<R[j]<<" ";
    }

    L[n1] = INT_MAX;  R[n2] = INT_MAX; //设置“哨兵”

    int i = 0,j = 0;
    for (int k = low; k <= high; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i += 1;
        }
        else {
            A[k] = R[j];
            j += 1;
        }
    }
}

void merge_v2(vector<int>&A,int low,int mid,int high) {
    int n1 = mid - low + 1;//左数组的长度
    int n2 = high - mid;//右数组的长度

    vector<int> L(n1);
    vector<int> R(n2);

    //复制数组
    for (int i = 0; i < n1; i++) {
        L[i] = A[low + i];
        //std::cout<<L[i]<<" ";
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
        //std::cout<<R[j]<<" ";
    }

    int i = 0,j = 0;
    int k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        }
        else {
            A[k++] = R[j++];
        }
    }
    //拷贝剩余元素
    while (i < n1) {
        A[k++] = L[i++];
    }
    while (j < n2) {
        A[k++] = R[j++];
    }
}

void mergeSort(vector<int> &A,int low,int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;//防止溢出
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge_v2(A, low, mid, high);
    }
}

#endif //ALGORITHMS_MERGESORT_H