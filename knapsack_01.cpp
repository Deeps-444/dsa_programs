#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// KNAPSACK - 0/1

struct Item
{
    int value;
    int weight;
};

int totalCostCal(vector<Item> &items, int n, int maxW)
{
    // dp table is needed
    vector<vector<int>> dp(n + 1, vector<int>(maxW + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int c = 1; c <= maxW; c++)
        { // c = capacity
            if (items[i - 1].weight <= c)
            {
                int rem = c - items[i - 1].weight; // remaining weight
                dp[i][c] = max(items[i - 1].value + dp[i - 1][rem], dp[i - 1][c]);
                // max between( [value of ith item + best value by remaning cap], [best value by previous combination of items] )
            }
            else
            {
                dp[i][c] = dp[i - 1][c];
            }
        }
    }
    return dp[n][maxW];
}

int main()
{
    int n, maxW;
    cout << "--------------0/1KNAPSACK PROBLEM---------------" << endl;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight of Knapsack: ";
    cin >> maxW;
    vector<Item> items(n);
    cout << "Enter item value and its weight: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    int result = totalCostCal(items, n, maxW);
    cout << "total cost is : " << result << endl;
    return 0;
}