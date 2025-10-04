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

    //找到最大值
    static int heapMaximum(vector<int> &A) {
        buildMaxHeap(A);
        return A[0];
    }

    //提取最大值并维护堆
    static int heapExtractMax(vector<int> &A, int& heap_size) {
        if (heap_size < 1) {
            throw runtime_error("堆 underflow");
        }

        int max = A[0];//最大值在根节点
        A[0] = A[A.size() - 1];//将最后一个元素移到根
        heap_size = heap_size - 1;// 堆大小减一
        maxHeapify_rec(A,heap_size, 0);//修复根节点

        return max;
    }

    // HEAP-INCREASE-KEY: 将 A[i] 的值增加为 new_key
    static void heapIncreaseKey(vector<int> &A, int i, int new_key) {
        // 新值不能小于原值
        if (new_key < A[i]) {
            throw invalid_argument("New key is smaller than current key");
        }
        A[i] = new_key;  // 更新值

        // 向上“上浮”，直到满足堆性质
        while (i > 0) {
            int parent = (i - 1) / 2;  // 父节点索引

            if (A[parent] >= A[i]) {
                break;  // 父节点更大，已满足堆性质
            }

            swap(A[i], A[parent]);  // 否则交换
            i = parent;             // 上移到父节点继续
        }
    }

    // MAX-HEAP-INSERT: 插入新元素
    static void maxHeapInsert(vector<int>& A, int key) {
        A.push_back(INT_MIN);           // 先在末尾插入一个最小值
        heapIncreaseKey(A, A.size() - 1, key);  // 提升为 key，自动上浮
    }

    // HEAP-DELETE: 删除下标 i 处的元素
    static void heapDelete(vector<int>& A, int& heap_size, int i) {
        // 用最后一个元素覆盖要删除的位置
        A[i] = A[heap_size - 1];
        heap_size--;  // 缩小堆大小

        if (heap_size == 0) return;// 堆空了

        // 方法：比较当前值与其父节点，若更大则上浮；否则尝试下沉(maxHeapify)
        if (i > 0) {
            int parent = (i - 1) / 2;// 父节点索引
            if (A[parent] < A[i]) {
                // 向上“上浮”，直到满足堆性质
                while (i > 0) {
                    if (A[parent] >= A[i]) {
                        break;  // 父节点更大，已满足堆性质
                    }

                    swap(A[i], A[parent]);  // 否则交换
                    i = parent;             // 上移到父节点继续
                }
            }
        }
        // 否则尝试下沉（可能是变小了或相等）
        maxHeapify_rec(A, heap_size, i);
    }

};


#endif //ALGORITHMS_MAXHEAPIFY_H