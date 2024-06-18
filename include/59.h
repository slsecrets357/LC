#include <vector>
#include <numeric>

using namespace std;
class Solution59 {
public:
    //59 spiral matrix 2
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> out(n, vector<int>(n));
      int sign = 1;
      int sign_counter = 0;
      int count = 1;
      int count2 = 0;
      bool rowIterate = true;
      int row = 0;
      int col = 0;
      int j = n;
      out[0][0] = 1;
      for (int i = 0; i< n*n; i++) {
        // printf("row: %d, col: %d, num: %d\n", row, col, i+1);
        out[row][col] = i+1;
        count2++;
        if(count2 >= j) {
          count2 = 0;
          // printf("here: i:%d, j:%d, count:%d\n", i, j, count);
          count++;
          sign_counter++;
          if(sign_counter > 1) {
            sign *= -1;
            sign_counter = 0;
          }
          if(count >= 2) {
            count = 0;
            j--;
          }
          rowIterate = !rowIterate;
        }
        if (rowIterate) {
          col = col + 1*sign;
        } else {
          row = row + 1*sign;
        }
      }
      return out;
    }
    //1

    // 1 2
    // 4 3

    // 1 2 3
    // 8 9 4
    // 7 6 5

    // 1  2  3  4
    // 12 13 14 5 
    // 11 16 15 6 
    // 10 9  8  7


    // soln1
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int min = 0;
    //     for (int i = 0; i<nums.size(); i++) {
    //       int cumsum = 0;
    //       int localmin = 0;
    //       for(int j = i; j<nums.size(); j++) {
    //         cumsum += nums[j];
    //         localmin ++;
    //         if (cumsum >= target) break;
    //       }
    //       if (cumsum >= target && (localmin < min || min==0)) min = localmin;
    //     }
    //     return min;
    // }

    int minSubArrayLen(int target, vector<int>& nums) {
      if (nums.empty()) return 0;
      int cumsum = 0;
      int min = 0;
      int left = 0;
      int right = 0;
      int localmin = 0;
      while (right < nums.size()) {
        cumsum += nums[right];
        while(cumsum >= target) {
          localmin = right - left +1;
          if (localmin < min || min == 0) min = localmin;
          cumsum -= nums[left++];
        }
        right ++;
      }
      return min;
    }
};
