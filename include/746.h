#include <vector>
using namespace std;

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> lut(n, 0);
        lut[n-1] = cost[n-1];
        lut[n-2] = cost[n-2];
        for(int i = n-3; i>=0; --i) {
            lut[i] = std::min(lut[i+1], lut[i+2]) + cost[i];
        }
        return std::min(lut[0], lut[1]);
    }
};