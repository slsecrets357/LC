#include <vector>
#include <numeric>
using namespace std;

class Solution494 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // left - right = target, left + right = sum, left = (sum+target)/2
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if ((target + sum) % 2 == 1) return 0;
        if (abs(target) > sum) return 0;
        int left = (sum+target)/2;
        int capacity = 10001;
        vector<int> dp(capacity + 1, 0);
        for(int i = 0; i<nums.size(); ++i) {
          for(int j = left; j>=nums[i]; --j) {
            dp[j] = std::max(dp[j], nums[i]+dp[j-nums[i]]);
          }
        }
    }
};