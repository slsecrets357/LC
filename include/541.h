#include <vector>
#include <string>
using namespace std;

class Solution541 {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        int j = 0;
        while(true) {
          if (i>=s.size()) break;
          j = i + k - 1;
          if (i+k >= s.size()) j = s.size()-1;
          int i2 = i;
          int j2 = j;
          while(i2<j2) {
            swap(s[i2], s[j2]);
            j2--;
            i2++;
          }
          i += 2*k;
        }
        return s;
    }
};