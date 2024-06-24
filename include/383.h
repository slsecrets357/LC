#include <string>
using namespace std;

class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int array[26];
        for(char c: magazine) {
            array[c - 'a'] ++;
        }
        for(char c: ransomNote) {
            array[c-'a']--;
            if(array[c-'a'] < 0) return false;
        }
        return true;
    }
};