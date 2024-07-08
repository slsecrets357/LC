#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i<gas.size(); i++) {
            int diff = gas[i]-cost[i];
            curSum+=diff;
            totalSum+=diff;
            if(curSum < 0) {
                start = i+1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     vector<int> diff(gas.size(), 0);
    //     int min = 100;
    //     int curSum = 0;
    //     for(int i = 0; i<gas.size(); i++) {
    //         diff[i] = gas[i]-cost[i];
    //         curSum+=diff[i];
    //         if(curSum < min) min = curSum;
    //     }
    //     if (curSum < 0) return -1;
    //     if(min>=0) return 0;
    //     for (int i = gas.size()-1; i>=0; --i) {
    //         min+=diff[i];
    //         if(min>=0) return i;
    //     }
    //     return -1;
    // }
};