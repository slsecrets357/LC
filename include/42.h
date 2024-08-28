#include <vector>
#include <stack>
using namespace std;

class Solution42 {
public:
    int trap0(vector<int>& height) {
        int out = 0;
        int n = height.size();
        vector<int> lefts(n, 0);
        vector<int> rights(n, 0);
        lefts[0] = height[0];
        for(int i = 1; i<n; ++i) {
            lefts[i] = std::max(height[i], lefts[i-1]);
        }
        rights[n-1] = height[n-1];
        for(int i = n-2; i>=0; --i) {
            rights[i] = std::max(height[i], rights[i+1]);
        }
        for(int i = 0; i<n; ++i) {
            int c = std::min(lefts[i], rights[i]) - height[i];
            out+=c;
        }
        return out;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> out(n, -1);
        stack<int> st;
        st.push(0);
        int sum = 0;
        for(int j = 0; j<n; ++j) {
            int i = j;
            if(height[i] < height[st.top()]) {
                st.push(i);
            } else if(height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while(!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
    }
};