#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> readMatrix(const string &filename)
{
    ifstream file(filename);
    vector<vector<int>> matrix;
    string token;

    while (true)
    {
        vector<int> row;
        string line;
        if (!getline(file, line))
            break;
        stringstream ss(line);

        while (ss >> token)
        {
            if (token == "INF")
                row.push_back(INF);
            else
                row.push_back(stoi(token));
        }
        if (!row.empty())
            matrix.push_back(row);
    }
    return matrix;
}

void floydWarshall(vector<vector<int>> &dist, vector<vector<int>> &next)
{
    int n = dist.size();
    next.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] != INF)
                next[i][j] = j;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
}

vector<int> getPath(int u, int v, const vector<vector<int>> &next)
{
    if (next[u][v] == -1)
        return {};
    vector<int> path = {u};
    while (u != v)
    {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (int val : row)
            cout << (val == INF ? "INF" : to_string(val)) << " ";
        cout << "\n";
    }
}

int main()
{

    vector<vector<int>> dist = readMatrix("distances.txt");

    if (dist.empty())
    {
        cout << "Error: distance matrix is empty. Check file path/format!\n";
        return 0;
    }

    cout << "Initial Distance Matrix:\n";
    printMatrix(dist);

    vector<vector<int>> next;
    floydWarshall(dist, next);

    cout << "\nShortest Distance Matrix:\n";
    printMatrix(dist);

    // example
    int start = 0, end = 3;
    string cityNames = "ABCD";

    vector<int> path = getPath(start, end, next);

    if (!path.empty())
    {
        cout << "\nShortest distance from City " << cityNames[start]
             << " to City " << cityNames[end] << ": " << dist[start][end] << "\n";
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << cityNames[path[i]];
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << "\n";
    }
    else
    {
        cout << "No path exists!\n";
    }

    return 0;
}
