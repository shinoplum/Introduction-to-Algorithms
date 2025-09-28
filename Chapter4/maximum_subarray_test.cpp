//
// Created by shinoship on 2025/9/28.
//
#include"MaximumSubarray.h"
#include<iostream>
using namespace std;
int main() {
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    subarray_result result = find_max_subarray(A, 0, A.size() - 1);

    cout << "Max subarray from index " << result.left_index
         << " to " << result.right_index
         << ", sum = " << result.sum << endl;

    return 0;
}