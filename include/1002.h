#include <string>
#include <vector>

using namespace std;

class Solution1002 {
public:
    vector<string> commonChars(vector<string>& words) {
        int record0[26] = {0};
        for(auto letter: words[0]) {
            record0[letter - 'a'] ++;
        }
        for(int i = 1; i<words.size(); i++) {
            int record1[26] = {0};
            string& word = words[i];
            for(auto letter: word) {
                record1[letter - 'a'] ++;
            }
            for (int j = 0; j<26; j++) {
                if(record1[j] < record0[j]) record0[j] = record1[j];
            }
        }
        vector<string> out;
        for(int i = 0; i<26; i++) {
            int f = record0[i];
            for(int j=0; j<f; j++) {
                string s = "";
                s += 'a'+i;
                out.push_back(s);
            }
        }
        return out;
    }
};