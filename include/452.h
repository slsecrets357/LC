#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution452 {
public:
    static bool cmp(const vector<int> &p1, const vector<int> &p2) {
        if(p1[0] == p2[0]) return p1[1] < p2[1];
        return p1[0] < p2[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;
        std::sort(points.begin(), points.end(), cmp);
        int last_x = points[0][1];
        printf("lastx: %d\n", last_x);
        for(int i = 1; i<points.size(); ++i) {
            std::cout << points[i][0] << "," << points[i][1] << std::endl;
            if(points[i][0] > last_x) {
                printf("lastx: %d, point: (%d, %d)\n", last_x, points[i][0], points[i][1]);
                last_x = points[i][1];
                count++;
            } else {
                last_x = std::min(last_x, points[i][1]);
            }
        }
        return count;
    }
};