#include <stdio.h>

struct Solution {
    int (*maxProfit)(int* prices, int len);
};

int maxProfit(int* prices, int len) {
    int sub = prices[0];
    int maxdiff = 0;
    for (int i = 1; i < len; i++) {
        if (prices[i] < sub) {
            sub = prices[i];
        }
        int curr = prices[i] - sub;
        maxdiff = (curr > maxdiff) ? curr : maxdiff;
    }
    if (maxdiff == 0) {
        return 0;
    }
    return maxdiff;
}

int main() {
    int stockPrices[] = {7, 1, 5, 3, 6, 4};
    int len = sizeof(stockPrices) / sizeof(stockPrices[0]);

    struct Solution sol;
    sol.maxProfit = maxProfit;
    int result = sol.maxProfit(stockPrices, len);

    printf("Maximum profit: %d\n", result);

    return 0;
}
