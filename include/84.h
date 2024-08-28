#include <vector>
#include <stack>
using namespace std;

class Solution84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(0);
        int result = 0;
        for(int i = 1; i<heights.size(); ++i) {
            if(heights[i] > heights[st.top()]) {
                st.push(i);
            } else if(heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while(!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left -1;
                        int h = heights[mid];
                        result = max(result, w*h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};