#include <vector>
using namespace std;
class Solution343 {
public:
    int integerBreak(int n) {
        vector<int> product(n+1,0);
        product[1] = 1;
        for(int i = 2; i<=n; i++) {
            int max1 = 0;
            for(int j = 1; j<=i/2; j++) {
                int a = std::max(product[j], j);
                int b = std::max(product[i-j], i-j);
                int p1 = a * b;
                if(p1>max1) max1 = p1;
            } 
            product[i] = max1;
            printf("product %d: %d\n", i, product[i]);
        }
        return product[n];
    }
};