#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        for (int i =0; i< nums.size(); i++) {
            if(nums[i] > target && nums[i]>=0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            for (int v = i+1; v<nums.size(); v++) {
                if (nums[v] + nums[i] > target && nums[v] + nums[i] >= 0) break;
                if (v>i+1 && nums[v] == nums[v-1]) continue;
                int j = v+1;
                int k = nums.size()-1;
                while (k>j) {
                    int c = nums[i] + nums[j] + nums[k] + nums[v];
                    if (c == target) {
                        out.push_back(vector<int>{nums[i], nums[j], nums[k], nums[v]});
                        while (k>j && nums[j] == nums[j+1]) j++;
                        while (k>j && nums[k] == nums[k-1]) k--;
                        k--;
                        j++;
                    } else if (c >target ) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }
        }
        return out;
    }
};