#include <string>

using namespace std;
class Solution242 {
public:
    bool isAnagram(string s, string t) {
        int lettersS[26];
        int lettersT[26];
        for(auto letter: s) {
            lettersS[letter - 'a'] ++;
        }
        for(auto letter: t) {
            lettersT[letter - 'a'] ++;
        }
        for(int i=0; i<26; i++) {
            if(lettersT[i]!=lettersS[i]) return false;
        }
        return true;
    }
};