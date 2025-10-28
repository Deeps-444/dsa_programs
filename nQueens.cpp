#include <iostream>
#include <vector>
#include <string>
// n queens - similar to graph coloring
using namespace std;

// function to check security
bool isSafe(int row, int col, vector<string> &board, int n)
{
    /* we will be moving row wise */
    // for upper - left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    // for upper rows
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    // for upper right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(int row, vector<string> &board, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        // check if the unit is safe or not
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(row + 1, board, n, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNqueens(int n)
{
    // this function is for making board and calling the main func
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    solve(0, board, n, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    // accoridng to number of queeens = size of matirx will be decided
    // nxn
    vector<vector<string>> soln;
    // cout << "ok";
    soln = solveNqueens(n);
    cout << "The number of solutions are: " << soln.size() << endl;

    cout << "Solutions: " << endl;
    for (auto &board : soln)
    {
        for (auto &row : board)
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}