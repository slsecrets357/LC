#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution435 {
public:
    static bool cmp(const vector<int> &p1, const vector<int> &p2) {
        if(p1[0] == p2[0]) return p1[1] < p2[1];
        return p1[0] < p2[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 1;
        std::sort(intervals.begin(), intervals.end(), cmp);
        int last_x = intervals[0][1];
        printf("lastx: %d\n", last_x);
        for(int i = 1; i<intervals.size(); ++i) {
            std::cout << intervals[i][0] << "," << intervals[i][1] << std::endl;
            if(intervals[i][0] >= last_x) {
                printf("lastx: %d, point: (%d, %d)\n", last_x, intervals[i][0], intervals[i][1]);
                last_x = intervals[i][1];
                count++;
            } else {
                last_x = std::min(last_x, intervals[i][1]);
            }
        }
        return intervals.size()-count;
    }
};