#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution1049 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int out = 0;
        int capacity = 10001;
        int target = sum/2;
        vector<int> dp(capacity + 1, 0);
        for(int i = 0; i<stones.size(); ++i) {
          for(int j = target; j>=stones[i]; --j) {
            dp[j] = std::max(dp[j], stones[i]+dp[j-stones[i]]);
          }
        }
        out += sum - (dp[target])*2;
        return out;
    }
};