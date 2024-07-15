#include <cmath>
class Solution70 {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int prev2 = 1;
        int prev = 2;
        for(int i = 3; i<=n; i++) {
            int sum = prev+prev2;
            prev2 = prev;
            prev = sum;
        }
        return prev;
    }
};