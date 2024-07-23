#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution416 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int capacity = 10001;
        int target = sum/2;
        vector<int> dp(capacity + 1, 0);
        for(int i = 1; i<nums.size(); ++i) {
          for(int j = capacity; j>=nums[i]; --j) {
            dp[j] = std::max(dp[j], nums[i]+dp[j-nums[i]]);
          }
        }
        return dp[target] == target;
    }
    //s1
    // bool canPartition(vector<int>& nums) {
    //     int sum = std::accumulate(nums.begin(), nums.end(), 0);
    //     if (sum % 2 == 1) return false;
    //     int capacity = 10001;
    //     int target = sum/2;
    //     vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, 0));
    //     for(int i = 1; i<nums.size(); ++i) {
    //       for(int j = 1; j<capacity; ++j) {
    //         if(nums[i] <= j) {
    //           dp[i][j] = std::max(dp[i-1][j], nums[i]+dp[i-1][j-nums[i]]);
    //         } else {
    //           dp[i][j] = dp[i-1][j];
    //         }
    //       }
    //     }
    //     return dp[nums.size()-1][target] == target;
    // }
};