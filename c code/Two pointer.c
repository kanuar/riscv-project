#include <stdio.h>

int maxProfit(int* prices, int n) {
    int maxProfit = 0;

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
    int prices[] = {8, 4, 6, 9, 5};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, n);
    printf("Maximum profit: %d\n", result);

    return 0;
}
