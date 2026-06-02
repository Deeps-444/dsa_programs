#include <iostream>
using namespace std;

// subset proble
void rec(int i, vector<int> parentTaken)
{
    // base case
    if (i >= n)
    {
        // print the subset
        cout << "set is : ";
        for (int i : parenTaken)
        {
            cout << parentTaken[i];
        }
    }
    rec(i + 1, parentTaken);
}

// using bit maniplation
void solve()
{
    for (int sub = 0; sub <= (1 << n); sub++)
    {
        for (int bit = 0; bit < n; bit++)
        {
            if ((sub & (1 << bit)) == 0)
            {
                // skipping this
                continue;
            }
            cout << arr[bit];
        }
    }
}

void main
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    return 0;
}