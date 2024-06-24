#include <unordered_set>
using namespace std;

class Solution202 {
public:
    bool isHappy(int n) {
        unordered_set<int> set1;
        int num = n;
        while(true) {
            int sum = 0;
            int num2 = num;
            while(num2) {
                sum += (num2%10) * (num2%10);
                num2 *= 1/10;
            }
            if(sum==1) return true;
            if(set1.find(sum) != set1.end()) return false;
            set1.insert(sum);
            num = sum;
        }
    }
};