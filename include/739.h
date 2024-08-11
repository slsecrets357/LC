#include <vector>
#include <stack>
using namespace std;

class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        st.push(0);
        vector<int> out(n, 0);
        for (int i=0; i<n; ++i) {
            if(temperatures[i] < temperatures[st.top()]) {
                st.push(i);
            } else if (temperatures[i] == temperatures[st.top()]) {
                st.push(i);
            } else {
                while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    out[st.top()] = i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return out;
    }
};