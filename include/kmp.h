#include <vector>
#include <string>
using namespace std;

class KMP {
public:
    vector<int> getNext(string s) {
        vector<int> next(s.size(), 0);
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    int match(string s, string p) {
        vector<int> next = getNext(p);
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j > 0 && s[i] != p[j]) {
                j = next[j-1];
            }
            if (s[i] == p[j]) {
                j++;
            }
            if (j == p.size()) {
                return i - j + 1;
            }
        }
        return -1;
    }

    vector<int> getNext(string s) {
        vector<int> next(s.size(), 0);
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while(j>0 && s[i] != s[j]) {
                j = next[j-1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
};