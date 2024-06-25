#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution151 {
public:
    string reverseWords(string s) {
      
    }

    //S1
    // string reverseWords(string s) {
    //     string out;
    //     int i = s.size()-1;
    //     while(i>=0) {
    //       while(i>=0 && s[i] == ' ') {
    //         i--;
    //         if(i==-1){
    //           out = out.substr(0, out.size()-1);
    //           return out;
    //         }
    //       }
    //       int j = i;
    //       int count = 0;
    //       while(j >= 0 && s[j] != ' ') {
    //         j--;
    //         count++;
    //       }
    //       std::cout << "string: " << s.substr(j+1, count) + " " << std::endl;
    //       out+=s.substr(j+1, count) + " ";
    //       i = j;
    //     }
    //     out = out.substr(0, out.size()-1);
    //     return out;
    // }
};