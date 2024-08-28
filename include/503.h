#include <vector>
#include <stack>
using namespace std;

class Solution503 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n, -1);
        stack<int> st;
        st.push(0);
        for(int j = 0; j<2*n; ++j) {
            int i = j;
            if(i>=n) i-=n;
            printf("i: %d\n", i);
            if(nums[i] <= nums[st.top()]) {
                st.push(i);
            } else {
                while(!st.empty() && nums[i] > nums[st.top()]) {
                    if(out[st.top()] == -1) out[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return out;
    }
};