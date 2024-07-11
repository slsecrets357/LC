#include <vector>
#include <cmath>
using namespace std;

class Solution738 {
public:
    int monotoneIncreasingDigits(int n) {
        if(n == 0) return 0;
        if(n/10 == 0) return n;
        vector<int> digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int out = 0;
        int flag = -1;
        for(int i =0; i<digits.size()-1; ++i) {
            if(digits[i] < digits[i+1]) {
                digits[i+1]--;
                flag = i;
            }
        }
        for (int i = flag; i>=0; i--) {
            digits[i] = 9;
        }
        for(int i = 0; i<digits.size();++i) {
            out+= digits[i] * std::pow(10, i);
        }
        return out;
    }
};