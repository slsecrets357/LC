#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution135 {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int i = 1; i<ratings.size(); ++i) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int i = ratings.size()-2; i>=0; --i) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        return std::accumulate(candies.begin(), candies.end(), 0);
    }
    // int candy(vector<int>& ratings) {
    //     int sum = 1;
    //     int val = 1;
    //     int pos = -1;
    //     int last = 0;
    //     int posCount = -1;
    //     for(int j = 1; j<ratings.size(); j++) {
    //         if(ratings[j] > ratings[j-1]) {
    //             val++;
    //             sum+=val;
    //             if(pos == -1) {
    //                 pos = 1;
    //                 posCount = 1;
    //                 posCount ++;
    //             }
    //             else if (pos == 1) {
    //                 if(posCount == -1) posCount = 1;
    //                 posCount ++;
    //             } else if (pos != 1) {
    //                 if(pos==0) last = j;
    //                 pos = 1;
    //                 posCount = 1;
    //             }
    //         } else if(ratings[j] == ratings[j-1]) {
    //             posCount = 1;
    //             last = j+1;
    //             val = 1;
    //             sum+=val;
    //             pos = -1;
    //         } else {
    //             if(val>1) {
    //                 val = 1;
    //                 sum+=val;
    //             } else {
    //                 sum += j-last+1;
    //                 if(posCount!=-1 && j-last+1 >= posCount) sum++;
    //             }
    //             if(pos != 0) {
    //                 if(pos == 1) last = j;
    //                 pos = 0;
    //             }
    //         }
    //         printf("j: %d, sum: %d, val:%d, pCount:%d, last:%d\n", j, sum, val,posCount,last);
    //     }
    //     return sum;
    // }
};