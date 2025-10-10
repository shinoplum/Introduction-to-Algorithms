//
// Created by shinoship on 2025/10/4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

struct Point {
    double x, y;
};

//两点之间的距离
double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}


double bitonicTSP(const vector<Point>& input) {
    int n = input.size();
    if (n <= 1) return 0.0;
    if (n == 2) return 2.0 * dist(input[0], input[1]);

    vector<Point> points = input;

    vector<vector<double>> dp(n, vector<double>(n, 1e10));
    vector<vector<double>> d(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = dist(points[i], points[j]);

    dp[1][0] = d[1][0];

    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < i - 1; ++j) {
            dp[i][j] = dp[i-1][j] + d[i-1][i];
        }
        dp[i][i-1] = 1e10;
        for (int k = 0; k < i - 1; ++k) {
            dp[i][i-1] = min(dp[i][i-1], dp[i-1][k] + d[k][i]);
        }
    }

    return dp[n-1][n-2] + d[n-2][n-1];
}
