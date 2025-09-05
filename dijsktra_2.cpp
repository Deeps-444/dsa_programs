#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int minDist(vector<int> &tim, vector<bool> &visited, int n)
{
    int minValue = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && tim[i] < minValue)
        {
            minValue = tim[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// dijkstra algorithm
void dijkstra(vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    vector<int> tim(n, INT_MAX);
    vector<bool> visited(n, false);

    tim[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDist(tim, visited, n);
        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && tim[u] + graph[u][v] < tim[v])
            {
                tim[v] = tim[u] + graph[u][v];
            }
        }
    }

    // output distances
    cout << "Shortest travel times from node " << src + 1 << ":\n";
    for (int i = 0; i < n; i++)
    {
        if (i == src)
            continue;
        if (tim[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << tim[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Example input (hardcoded)
    int N = 5, M = 6;
    vector<vector<int>> graph(N, vector<int>(N, 0));

    // edges
    graph[0][1] = graph[1][0] = 4;
    graph[0][2] = graph[2][0] = 2;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 5;
    graph[2][4] = graph[4][2] = 10;
    graph[3][4] = graph[4][3] = 3;

    int S = 1;

    dijkstra(graph, S - 1);

    return 0;
}
