#include <vector>
#include <iostream>
using namespace std;

class Solution376 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int count = 1;
        int prevDiff = 0;
        int curDiff = 0;
        for(int i =0; i<nums.size()-1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((prevDiff <= 0 && curDiff > 0) || (prevDiff >= 0 && curDiff < 0)) {
                count++;
                prevDiff = curDiff;
            }
        }
        return count;
    }
};