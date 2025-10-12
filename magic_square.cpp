#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the magic square: ";
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "This program works only for odd-sized magic squares." << endl;
        return 0;
    }

    int magic[n][n];

    // initialize
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic[i][j] = 0;

    int i = 1;
    int r = 0;
    int c = n / 2;

    while (i <= n * n)
    {
        magic[r][c] = i++;

        int nextRow = (r - 1 + n) % n;
        int nextCol = (c + 1) % n;

        if (magic[nextRow][nextCol] != 0)
        {
            r = (r + 1) % n;
        }
        else
        {
            r = nextRow;
            c = nextCol;
        }
    }

    // Print
    cout << "\nMagic Square of size " << n << ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << magic[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
