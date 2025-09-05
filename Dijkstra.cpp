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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u - 1][v - 1] = t;
        graph[v - 1][u - 1] = t;
    }

    int S;
    cin >> S;
    dijkstra(graph, S - 1);

    return 0;
}
