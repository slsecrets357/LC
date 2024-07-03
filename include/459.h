#include <string>
#include <vector>
using namespace std;

class Solution459 {
public:
    bool repeatedSubstringPattern(string s) {
        string s2 = s+s;
        s2.erase(s2.begin());
        s2.erase(s2.end()-1);
        if(s2.find(s) != std::string::npos) return true;
        return false;
    }
};