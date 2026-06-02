#include <iostream>
using namespace std;

void rec(int index, int remainingCost, int n, vector<int> &price, vector<int> &pages)
{
    // base condition'

    // resursive relation
    int notTake = rec(index + 1, remainingCost, n, price, pages);

    int take = 0;
    if (price[index] <= remainingCost)
    {
        take = rec(index + 1, remainingCost - price[index], 0, price, pages +)
    }
}

int main()
{
    return 0;
}