#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int sub = prices[0];
        int maxdiff = 0;
        for(int i = 1; i < len; i++) {
            if(prices[i] < sub) {
                sub = prices[i];
            }
            int curr = prices[i] - sub;
            maxdiff = max(curr, maxdiff);
        }
        if(maxdiff == 0) {
            return 0;
        }
        return maxdiff;
    }
};

int main() {
    vector<int> stockPrices = {7, 1, 5, 3, 6, 4};

    Solution sol; 
    int result = sol.maxProfit(stockPrices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}
