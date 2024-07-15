#include <vector>
#include <iostream>
using namespace std;

class Solution62 {
public:
    unsigned long long binomialCoefficient(int n, int k) {
        if (k > n - k) {
            k = n - k; // C(n, k) == C(n, n - k)
        }
        unsigned long long result = 1;
        for (int i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    int uniquePaths(int m, int n) {
        return binomialCoefficient(m + n - 2, m - 1);
    }
    //s1
    // int uniquePaths(int m, int n) {
    //     if(m==1 || n==1) return 1;
    //     vector<vector<int>> lut(m, vector<int>(n, 0));
    //     lut[m-2][n-1] = 1;
    //     lut[m-1][n-2] = 1;
    //     for(int i = m-1; i>=0; --i) {
    //         for(int j = n-1; j>=0; --j) {
    //             if(i==m-1 || j == n-1) {
    //                 lut[i][j] = 1;
    //             } else {
    //                 lut[i][j] = lut[i+1][j] + lut[i][j+1];
    //             }
    //         }
    //     }
    //     for(const auto &row : lut) {
    //         for(int val : row) {
    //             cout << val << " ";
    //         }
    //         cout << "\n";
    //     }
    //     return lut[0][0];
    // }
};