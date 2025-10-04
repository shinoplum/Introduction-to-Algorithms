//
// Created by shinoship on 2025/10/4.
//

#ifndef ALGORITHMS_CUTROD_H
#define ALGORITHMS_CUTROD_H
#include <climits>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

//递归处理
int cutRod(vector<int> &p, int n) {
    if (n == 0) return 0;
    int q = INT_MIN;
    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + cutRod(p,n - i));
    }
    cout << q << " " ;
    return q;
}

//带备忘的自顶向下方法
int memoizedCutRodAux(vector<int> &p, int n,vector<int> &r) {
    int q = 0;
    if (r[n] >= 0) return r[n];//计算过的值 直接返回
    if (n == 0) {
        q =0;
    }
    else {
        q = INT_MIN;
        for (int i = 1; i <= n; i++) {
            q = max(q, p[i] + memoizedCutRodAux(p, n - i, r));
        }
    }
    cout << q << " " ;
    r[n] = q;
    return q;
}

int memoizedCutRod(vector<int> &p, int n) {
    vector<int> r(n, -1);//设置为-1好作比较
    return memoizedCutRodAux(p, n, r);
}

//自底向上
int bottomUpCutRod(vector<int> &p, int n) {
    vector<int> r(n);
    r[0] = 0;
    int q = 0;
    for (int j = 1; j <= n; j++) {
        q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    cout << r[n] << " ";
    return r[n];
}

#endif //ALGORITHMS_CUTROD_H