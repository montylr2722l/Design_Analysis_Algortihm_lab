#include<bits/stdc++.h>
using namespace std;

struct item {
    int value;
    int weight;
};

int knapsack(int capacity, vector<item>& items) {

    int n = items.size();

    // dp[i][w] = maximum value using first i items
    // with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for(int i = 1; i <= n; i++) {

        for(int w = 1; w <= capacity; w++) {

            // Don't take the current item
            dp[i][w] = dp[i - 1][w];

            // Take the current item if it fits
            if(items[i - 1].weight <= w) {

                dp[i][w] = max(
                    dp[i][w],
                    items[i - 1].value +
                    dp[i - 1][w - items[i - 1].weight]
                );
            }
        }
    }

    return dp[n][capacity];
}

int main() {

    int n;

    cout << "Enter number of items: ";
    cin >> n;

    vector<item> items(n);

    cout << "\nEnter value and weight of each item:\n";

    for(int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;

    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;

    int maxProfit = knapsack(capacity, items);

    cout << "\nMaximum Profit = " << maxProfit << endl;

    return 0;
}