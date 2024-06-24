#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map1;
        for(int i=0; i<nums.size(); ++i) {
            int num = nums[i];
            auto iter = map1.find(target-num);
            if(iter != map1.end()) {
                return {iter->second, i};
            }
            map1.insert(pair<int,int>(num, i));
        }
        return {};
    }
};