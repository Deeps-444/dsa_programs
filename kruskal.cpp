#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(Edge const &other)
    {
        return w < other.w;
    }
};

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent); // path compression
}

void unionSets(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b)
    {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main()
{
    int V = 4, E = 5;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;
    vector<Edge> result;

    for (auto &e : edges)
    {
        if (findParent(e.u, parent) != findParent(e.v, parent))
        {
            cost += e.w;
            result.push_back(e);
            unionSets(e.u, e.v, parent, rank);
        }
    }

    cout << "Edges in MST:\n";
    for (auto &e : result)
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    cout << "Total Cost of MST: " << cost << endl;
}
