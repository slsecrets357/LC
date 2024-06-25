#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution15 {
public:
    //s1
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        for (int i =0; i< nums.size(); i++) {
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            unordered_set<int> uset;
            for(int j = i+1; j<nums.size(); j++) {
                if (j>i+2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]) continue;
                int c = 0-(nums[j]+nums[i]);
                if(uset.find(c) != uset.end()) {
                    out.push_back({nums[i], nums[j], c});
                    uset.erase(c);
                } else {
                    uset.insert(nums[j]);
                }
            }
        }
        return out;
    }

    //s2
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        // unordered_set<vector<int>> uset;
        sort(nums.begin(), nums.end());
        for (int i =0; i< nums.size(); i++) {
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while (k>j) {
                int c = nums[i] + nums[j] + nums[k];
                if (c == 0) {
                    // uset.insert({nums[i], nums[j], nums[k]});
                    out.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (k>j && nums[j] == nums[j+1]) j++;
                    while (k>j && nums[k] == nums[k-1]) k--;
                    k--;
                    j++;
                } else if (c >0 ) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return out;
    }
};