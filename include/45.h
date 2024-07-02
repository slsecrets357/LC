#include <vector>
#include <iostream>
using namespace std;

class Solution45 {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int i = 0;
        int count = 0;
        while(i<nums.size() && nums[i] != 0) {
          std::cout << i << std::endl;
          if(nums[i] + i >= nums.size()-1) return count+1;
          int j = 1;
          int k = j;
          int max = 0;
          for (j = 1; j<=nums[i]; j++) {
            if(i+j<nums.size() && nums[i+j] != 0 && nums[i+j] + j > max) {
              max = nums[i+j] + j;
              k = j;
            }
          }
          i += k;
          count++;
        }
        return count-1;
    }
};