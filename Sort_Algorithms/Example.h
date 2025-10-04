//
// Created by shinoship on 2025/9/21.
//

#ifndef ALGORITHMS_EXAMPLE_H
#define ALGORITHMS_EXAMPLE_H
#include <iostream>
#include <vector>
using namespace std;
#include<array>
//比较大小
    bool less(int v,int w) {
        return v < w;
    }
//交换函数
void exch(vector<int> &arr,int i,int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        // swap(arr[i],arr[j]);
    }
//打印数组
void show1(vector<int> &arr) {
        for (int i = 0;i < arr.size();i++) {
            std::cout << arr[i] << " ";
        }
    }
void show2(vector<int> &arr) {
        for (const auto i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
//判断数组是否有序
bool isSorted(vector<int> &arr) {
        for (int i = 1;i < arr.size();i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }

#endif //ALGORITHMS_EXAMPLE_H