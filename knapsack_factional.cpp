#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// items
struct item
{
    int value;
    int weight;
};

bool cmp(item a, item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
// knpasack
double knapsack(vector<item> items, int maxW)
{
    // first sortthe items: descending
    sort(items.begin(), items.end(), cmp);

    double totalcost = 0.0;
    int currWeight = 0;
    for (auto i : items)
    {
        if (currWeight + i.weight <= maxW)
        {
            currWeight += i.weight;
            totalcost += i.value;
        }
        else
        {
            int remain = maxW - currWeight;
            totalcost += i.value * ((double)remain / i.weight);
            break;
        }
    }

    return totalcost;
}

// knapsack fractional
int main()
{
    int n, maxW;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter max weight of knapsack: ";
    cin >> maxW;

    vector<item> items(n);
    cout << "Enter value and weight";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }
    double result = knapsack(items, maxW);
    cout << "\n total value: " << result << endl;
    return 0;
}