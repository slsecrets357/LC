#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution55 {
public:
    bool canJump(vector<int>& nums) {
      if(nums.size() == 1) return true;
      int coverArea = 0;
      for (int i = 0; i<=coverArea; i++) {
        if(coverArea >= nums.size()-1) return true;
        coverArea = std::max(i + nums[i], coverArea);
      }
      return false;
    }
};