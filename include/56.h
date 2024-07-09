#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution56 {
public:
    static bool cmp(const vector<int> &p1, const vector<int> &p2) {
        if(p1[0] == p2[0]) return p1[1] < p2[1];
        return p1[0] < p2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int count = 1;
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> out;
        int left = intervals[0][0];
        int last_x = intervals[0][1];
        printf("lastx: %d\n", last_x);
        for(int i = 1; i<intervals.size(); ++i) {
            std::cout << intervals[i][0] << "," << intervals[i][1] << std::endl;
            if(intervals[i][0] > last_x) {
                printf("lastx: %d, point: (%d, %d)\n", last_x, intervals[i][0], intervals[i][1]);
                out.push_back(vector<int>{left, last_x});
                last_x = intervals[i][1];
                left = intervals[i][0];
            } else {
                last_x = std::max(last_x, intervals[i][1]);
            }
        }
        out.push_back(vector<int>{left, last_x});
        return out;
    }
};