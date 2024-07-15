#include <vector>
using namespace std;
class Solution509 {
public:
    int fib(int n) {
        static vector<int> lut(31, -1);
        if(lut[n] != -1) return lut[n];
        if(n == 0) {
            lut[0] = 0;
            return 0;
        }
        if(n == 1) {
            lut[1] = 1;
            return 1;
        }
        lut[n] = fib(n-1) + fib(n-2);
        return lut[n];
    }
};