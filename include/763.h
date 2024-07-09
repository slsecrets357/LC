#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> out;
        vector<int> indices(27, 0);
        for (int i = 0; i<s.size(); ++i) {
          indices[s[i]-'a'] = i;
        }
        int last = 0;
        int farthest = 0;
        for (int i = 0; i<s.size(); ++i) {
          farthest = std::max(farthest, indices[s[i]-'a']);
          if(i == farthest) {
            out.push_back(i-last+1);
            last = i+1;
          }
        }
        return out;
    }
};