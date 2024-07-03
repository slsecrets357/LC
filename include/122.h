#include <vector>
#include <iostream>
using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
          int diff = prices[i] > prices[i-1];
          std::cout << diff << std::endl;
          if(diff > 0) profit += diff;
        }
        return profit;
    }
};