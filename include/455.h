#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = s.size()-1;
        int out = 0;
        for(int j = g.size()-1; j>=0; j--) {
            if (i>=0 && s[i] >= g[j]) {
                out++;
                i--;
            }
        }
        return out;
    }
};