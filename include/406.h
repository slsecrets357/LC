#include <vector>
#include <algorithm>
using namespace std;

class Solution406 {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), cmp);
        vector<vector<int>> out;
        for (int i = 0; i<people.size(); ++i) {
            int position = people[i][1];
            out.insert(out.begin()+position, people[i]);
        }
        return out;
    }
};