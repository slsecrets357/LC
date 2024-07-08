#include <vector>
#include <iostream>
using namespace std;

class Solution860 {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(2, 0);
        if(bills[0] != 5)return false;
        cash[0] = 1;
        for(int i = 1; i<bills.size(); ++i){
            if(bills[i] == 20) {
                if(cash[1] > 0 && cash[0] > 0) {
                    std::cout << "case1" <<std::endl;
                    cash[1]--;
                    cash[0]--;
                } else if(cash[0] > 2) {
                    std::cout << "case2" <<std::endl;
                    cash[0] -= 3;
                } else {
                    std::cout << "case3" <<std::endl;
                    return false;
                }
            } else if(bills[i] == 10) {
                if(cash[0] > 0) {
                    cash[0] --;
                    cash[1] ++;
                } else return false;
            } else cash[0]++;
        }
        return true;
    }
};