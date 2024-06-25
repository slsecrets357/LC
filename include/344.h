#include <vector>
using namespace std;

class Solution344 {
public:

    void reverseString(vector<char>& s) {
        //s1
        // int length = s.size();
        // for (int i = 0; i< length/2; ++i) {
        //   std::swap(s[i], s[length - 1 - i]);
        // }
        std::reverse(s.begin(), s.end());
    }
};