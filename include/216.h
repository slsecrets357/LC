#include <vector>
#include <iostream>
using namespace std;

class Solution216 {
public:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;

    void backtracking(int k, int n, int startIndex) {
        if(path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }

        for(int i = startIndex; i<=9; ++i) {
            path.push_back(i);
            sum+=i;
            backtracking(k, n, i+1);
            path.pop_back();
            sum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};