#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{

    for (int i = 0; i < row; i++)
        if (board[i][col] == 'S')
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'S')
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'S')
            return false;

    return true;
}

void solve(int row, vector<string> &board, vector<vector<string>> &result, int n)
{
    if (row == n)
    {

        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'S';
            solve(row + 1, board, result, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> secureServerDeployment(int n = 4)
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solve(0, board, result, n);
    return result;
}

int main()
{
    vector<vector<string>> configs = secureServerDeployment();

    cout << "Total valid configurations: " << configs.size() << "\n\n";
    for (int k = 0; k < configs.size(); k++)
    {
        cout << "Configuration " << k + 1 << ":\n";
        for (string row : configs[k])
            cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
