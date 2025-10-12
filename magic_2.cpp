#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    vector<ll> row(n, 0), col(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            row[i] += a[i][j];
            col[j] += a[i][j];
        }

    // Find the most common sum (the correct magic sum)
    unordered_map<ll, int> freq;
    for (auto x : row)
        freq[x]++;
    for (auto x : col)
        freq[x]++;

    ll S = 0;
    int best = 0;
    for (auto &p : freq)
        if (p.second > best)
            best = p.second, S = p.first;

    vector<int> badRows, badCols;
    for (int i = 0; i < n; ++i)
        if (row[i] != S)
            badRows.push_back(i);
    for (int j = 0; j < n; ++j)
        if (col[j] != S)
            badCols.push_back(j);

    // If everything looks "good", we still need to check all possible swaps
    vector<int> rows = badRows.empty() ? vector<int>(n) : badRows;
    vector<int> cols = badCols.empty() ? vector<int>(n) : badCols;
    if (badRows.empty())
        iota(rows.begin(), rows.end(), 0);
    if (badCols.empty())
        iota(cols.begin(), cols.end(), 0);

    // Try all pairs of cells among the relevant ones
    for (int r1 : rows)
    {
        for (int c1 : cols)
        {
            for (int r2 : rows)
            {
                for (int c2 : cols)
                {
                    if (r1 == r2 && c1 == c2)
                        continue;

                    int v1 = a[r1][c1], v2 = a[r2][c2];

                    ll new_r1 = row[r1] - v1 + v2;
                    ll new_r2 = row[r2] - v2 + v1;
                    ll new_c1 = col[c1] - v1 + v2;
                    ll new_c2 = col[c2] - v2 + v1;

                    bool ok = true;
                    if (r1 != r2 && (new_r1 != S || new_r2 != S))
                        ok = false;
                    if (c1 != c2 && (new_c1 != S || new_c2 != S))
                        ok = false;
                    if (ok)
                    {
                        cout << r1 + 1 << " " << c1 + 1 << " "
                             << r2 + 1 << " " << c2 + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cerr << "No swap found\n";
    return 0;
}
