#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution1005 {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                break;
            } else {
                if (k > 0) {
                    nums[i] *= -1;
                    k--;
                } else break;
            }
        }
        if (k > 0 && k%2!=0) {
            std::sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        for(int i = 0; i<nums.size(); i++) sum+=nums[i];
        return sum;
    }
};