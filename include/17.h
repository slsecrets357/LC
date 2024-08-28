#include <vector>
#include <string>
using namespace std;

class Solution17 {
public:
    vector<string> out;
    string path;
    vector<string> letterMap = {
        " ",    //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };
    void backtracking(string digits, int startIndex) {
        if(digits.size() == path.size()) {
            out.push_back(path);
            return;
        }
        int digit = digits[startIndex] - '0';  
        string letters = letterMap[digit]; 
        for(int i =0; i<letters.size(); ++i) {
        // for(char c: letterMap[startIndex]) {
            path.push_back(letters[i]); 
            backtracking(digits, startIndex+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return out;
        }
        backtracking(digits, 0);
        return out;
    }
};