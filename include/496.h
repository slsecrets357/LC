#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution496 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        vector<int> out(n1, -1);
        stack<int> st;
        st.push(0);
        unordered_map<int, int> umap;
        for(int i = 0; i<nums2.size(); ++i) {
            if(nums2[i] <= nums2[st.top()]) {
                st.push(i);
            } else {
                while(!st.empty() && nums2[i] > nums2[st.top()]) {
                    std::pair<int, int> pair(nums2[st.top()], nums2[i]);
                    umap.insert(pair);
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int i = 0; i<n1; ++i) {
            std::unordered_map<int, int>::const_iterator got = umap.find(nums1[i]);
            if(got != umap.end()) {
                out[i] = got->second;
            }
        }
        return out;
    }
};