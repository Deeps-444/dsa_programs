#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int minDist(vector<int> &dist, vector<bool> &visited, int n)
{
    int minValue = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < minValue)
        {
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Multi-source Dijkstra
void multiDijkstra(vector<vector<int>> &graph, vector<int> &safeZones)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    // Initialize safe zones with distance 0
    for (int sz : safeZones)
    {
        dist[sz] = 0;
    }

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDist(dist, visited, n);
        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output distances
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Example Input (hardcoded)
    int N = 5, M = 6, K = 2;
    vector<vector<int>> graph(N, vector<int>(N, 0));

    // edges
    graph[0][1] = graph[1][0] = 4;
    graph[0][2] = graph[2][0] = 2;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 5;
    graph[2][4] = graph[4][2] = 10;
    graph[3][4] = graph[4][3] = 3;

    // Safe zones (1-based in input → convert to 0-based)
    vector<int> safeZones = {1, 4}; // nodes 2 and 5

    multiDijkstra(graph, safeZones);

    return 0;
}
