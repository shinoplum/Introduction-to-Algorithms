//
// Created by shinoship on 2025/10/4.
//
#include <vector>
#include "CutRod.h"
#include <iostream>
using namespace std;

int main() {
    vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 6;
    cutRod(p, n);
    cout << endl;
    memoizedCutRod(p,n);
    cout << endl;
    //bottomUpCutRod(p ,n);
}