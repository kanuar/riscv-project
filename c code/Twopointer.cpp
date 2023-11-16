#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int n = prices.size();

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (prices[j] > prices[i]) {
                int diff = prices[j] - prices[i];
                if (diff > maxProfit) {
                    maxProfit = diff;
                }
            }
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {8,4,6,9,5};

    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
