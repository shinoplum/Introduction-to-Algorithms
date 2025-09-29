//
// Created by shinoship on 2025/9/28.
//

#ifndef ALGORITHMS_MAXHEAPIFY_H
#define ALGORITHMS_MAXHEAPIFY_H
#include<vector>
using namespace std;

//
class MaxHeap {
    public:
    //MAX-HEAPIFY:维护最大堆性质
    //递归实现
    static void maxHeapify_rec(vector<int> &A, int heap_size, int i) {
        int lchild = 2 * i + 1; //左孩子
        int rchild = 2 * i + 2;//右孩子
        int largest = i;//假设当前节点是最大值

        //比较左孩子
        if (lchild < heap_size && A[lchild] > A[i]) {
            largest = lchild;
        }

        //比较右孩子
        if (rchild < heap_size && A[rchild] > A[largest]) {
            largest = rchild;
        }

        //如果当前不是最大节点则下沉
        if (largest != i) {
            swap(A[i], A[largest]);
            maxHeapify_rec(A, heap_size, largest);
        }
    }

    static void maxHeapify(vector<int>& A, int start) {
        int i = start;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            int heap_size = A.size();

            if (left < heap_size && A[left] > A[largest])
                largest = left;
            if (right < heap_size && A[right] > A[largest])
                largest = right;

            if (largest == i) break;  // 堆性质已满足

            swap(A[i], A[largest]);
            i = largest;  // 继续下沉
        }
    }

    //BUILD-MAX_HEAP:构建最大堆
    static void buildMaxHeap(vector<int> &A) {
        int n = A.size();
        for (int i = n / 2 - 1; i >= 0; i--) {//子数组A([n/2] + 1...n)都是树的叶结点
            maxHeapify_rec(A, n, i);
        }
    }
};


#endif //ALGORITHMS_MAXHEAPIFY_H