#include <vector>
#include <unordered_map>
using namespace std;

class Solution454 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for (int a: nums1) {
            for (int b: nums2) {
                umap[a+b] ++;
            }
        }
        int count = 0;
        for (int c: nums3) {
            for (int d: nums4) {
                auto r = umap.find(0-(c+d));
                if(r != umap.end()) {
                    count+=r->second;
                }
            }
        }
        return count;
    }
};