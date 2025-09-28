//
// Created by shinoship on 2025/9/27.
//

#ifndef ALGORITHMS_MAXIMUM_SUBARRAY_H
#define ALGORITHMS_MAXIMUM_SUBARRAY_H
#include <climits>
#include <vector>

//分治法

class subarray_result {
    public:
    int left_index;//原书max_left
    int right_index;//原书max_right
    int sum;
    subarray_result(int left_index, int right_index, int sum)
        : left_index(left_index), right_index(right_index), sum(sum) {}
};

subarray_result find_max_crossing_subarray(std::vector<int>& A, int low,int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int left_index = mid;
    for (int i = mid; i >= low;i--) {
        sum = sum + A[i];
        if (left_sum < sum) {
            left_sum = sum;
            left_index = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int right_index = mid + 1;
    for (int j = mid + 1; j<= high;j++) {
        sum = sum + A[j];
        if (right_sum < sum) {
            right_sum = sum;
            right_index = j;
        }
    }

    return {left_index, right_index, left_sum + right_sum};
}

subarray_result find_max_subarray(std::vector<int>& A, int low, int high) {
    if (low == high) {
        return subarray_result(low, high,A[low]);
    }
    else {
        int mid = low + (high - low) / 2;
        subarray_result left_subarray = find_max_subarray(A,low,mid);
        subarray_result right_subarray = find_max_subarray(A,mid+1,high);
        subarray_result subarray_cross = find_max_crossing_subarray(A, low, mid, high);
        if (left_subarray.sum > right_subarray.sum && left_subarray.sum > subarray_cross.sum) {
            return left_subarray;
        }
        else if (right_subarray.sum > subarray_cross.sum && right_subarray.sum > left_subarray.sum) {
            return right_subarray;
        }
        else {
            return subarray_cross;
        }
    }
}
#endif //ALGORITHMS_MAXIMUM_SUBARRAY_H