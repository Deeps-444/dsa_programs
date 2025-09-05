#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find the unvisited node with minimum distance
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

// Dijkstra algorithm
void dijkstra(int n, int start, vector<vector<pair<int, int>>> &adj, vector<int> &tim)
{
    tim.assign(n, INT_MAX);
    vector<bool> visited(n, false);
    tim[start] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = minDist(tim, visited, n);
        if (u == -1)
            break;
        visited[u] = true;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v] && tim[u] + w < tim[v])
            {
                tim[v] = tim[u] + w;
            }
        }
    }
}

int main()
{
    int N = 6, M = 7;
    vector<vector<pair<int, int>>> adj(N);

    // Define edges (from Example Input)
    vector<int> u = {1, 2, 3, 4, 5, 1, 2};
    vector<int> v = {2, 3, 4, 5, 6, 6, 5};
    vector<int> w = {3, 4, 5, 6, 7, 2, 3};

    // Build adjacency list (0-based indexing)
    for (int i = 0; i < M; i++)
    {
        int a = u[i] - 1;
        int b = v[i] - 1;
        adj[a].push_back({b, w[i]});
        adj[b].push_back({a, w[i]}); // undirected
    }

    int S = 1 - 1; // Start node
    int V = 4 - 1; // Volcano node
    vector<int> timS(N), timV(N);

    // Run Dijkstra from S and V
    dijkstra(N, S, adj, timS);
    dijkstra(N, V, adj, timV);

    // Find safe nodes (timS[i] <= timV[i])
    vector<int> safeNodes;
    for (int i = 0; i < N; i++)
    {
        if (timS[i] <= timV[i])
            safeNodes.push_back(i + 1); // 1-based
    }

    // Output safe nodes
    if (safeNodes.empty())
        cout << "None\n";
    else
    {
        for (int node : safeNodes)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
