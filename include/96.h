#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n<=2) return n;
        vector<int> lut(n+1, 0);
        lut[0] = 1;
        lut[1] = 1;
        lut[2] = 2;
        for(int i = 3; i<=n; i++) {
            for(int j = 0; j<i; j++) {
                lut[i] += lut[j]*lut[i-j-1];
            }
        }
        return lut[n];
    }
};